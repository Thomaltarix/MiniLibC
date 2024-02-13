/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_memset
*/

#include "functions.h"

void *my_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
    void *handle;
    void *(*my_memcpy)(void *restrict, const void *restrict, size_t);
    char *error;

    handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return NULL;
    }
    my_memcpy = dlsym(handle, "memcpy");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return NULL;
    }
    my_memcpy(dest, src, n);
    dlclose(handle);
    return dest;
}

Test(memcpy, basic_test)
{
    char *src = "Hello World";
    char dest[12];
    int tmp;

    my_memcpy(dest, src, 12);
    tmp = memcmp(dest, src, 12);
    cr_assert_eq(tmp, 0);
}

Test(memcpy, size_0)
{
    char *src = "Hello World";
    char dest[12];
    int tmp;

    my_memcpy(dest, src, 0);
    tmp = memcmp(dest, src, 0);
    cr_assert_eq(tmp, 0);
}

Test(memcpy, no_sentence)
{
    char *src = "";
    char dest[12];
    int tmp;

    my_memcpy(dest, src, 1);
    tmp = memcmp(dest, src, 1);
    cr_assert_eq(tmp, 0);
}
