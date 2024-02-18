/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strpbrk
*/

#include "functions.h"

char *my_strpbrk(const char *s, const char *accept)
{
    char *handle;
    char *(*my_strpbrk)(const char *, const char *);
    char *error;

    handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return NULL;
    }
    my_strpbrk = dlsym(handle, "strpbrk");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return NULL;
    }
    my_strpbrk(s, accept);
    dlclose(handle);
    return my_strpbrk(s, accept);
}

Test(strpbrk, simple_sentence)
{
    char *src = "Hello";
    char *tmp;

    tmp = my_strpbrk(src, "l");
    cr_assert_str_eq(tmp, "llo");
}