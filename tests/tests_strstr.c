/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strstr
*/

#include "functions.h"

char *my_strstr(const char *haystack, const char *needle)
{
    char *handle;
    char *(*my_strstr)(const char *, const char *);
    char *error;

    handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return NULL;
    }
    my_strstr = dlsym(handle, "strstr");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return NULL;
    }
    my_strstr(haystack, needle);
    dlclose(handle);
    return my_strstr(haystack, needle);
}

Test(strstr, simple_sentence, .init = redirect_all_std)
{
    char *src = "Hello";
    char *tmp;

    tmp = my_strstr(src, "l");
    cr_assert_str_eq(tmp, "llo");
}