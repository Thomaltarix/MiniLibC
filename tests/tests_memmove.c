/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_memmove
*/

#include "functions.h"

void *my_memmove(void *dest, const void *src, size_t n)
{
    void *handle;
    void *(*my_memmove)(void *restrict, const void *restrict, size_t);
    char *error;

    handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return NULL;
    }
    my_memmove = dlsym(handle, "memmove");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return NULL;
    }
    my_memmove(dest, src, n);
    dlclose(handle);
    return dest;
}

Test(memmove, basic_test)
{
    char *src = "Hello World";
    char dest[12];
    int tmp;

    my_memmove(dest, src, 12);
    tmp = memcmp(dest, src, 12);
    cr_assert_eq(tmp, 0);
}

Test(memmove, size_0)
{
    char *src = "Hello World";
    char dest[12];
    int tmp;

    my_memmove(dest, src, 0);
    tmp = memcmp(dest, src, 0);
    cr_assert_eq(tmp, 0);
}

Test(memmove, no_string)
{
    char *src = "";
    char dest[12];
    int tmp;

    my_memmove(dest, src, 1);
    tmp = memcmp(dest, src, 1);
    cr_assert_eq(tmp, 0);
}

Test(memmove, no_string_2)
{
    char *src = "";
    char dest[12];
    int tmp;

    my_memmove(dest, src, 0);
    tmp = memcmp(dest, src, 0);
    cr_assert_eq(tmp, 0);
}

Test(memmove, overlap)
{
    char *src = "Hello World";
    char dest[12];
    int tmp;

    my_memmove(dest, src, 12);
    my_memmove(dest + 5, dest, 5);
    tmp = memcmp(dest, "HelloHello", 10);
    cr_assert_eq(tmp, 0);
}

Test(memmove, overlap_2)
{
    char *src = "Hello World";
    char dest[12];
    int tmp;

    my_memmove(dest, src, 12);
    my_memmove(dest + 6, dest, 5);
    tmp = memcmp(dest, "Hello Hello", 11);
    cr_assert_eq(tmp, 0);
}

Test(memmove, overlap_3)
{
    char *src = "Hello World";
    char dest[12];
    int tmp;

    my_memmove(dest, src, 12);
    my_memmove(dest + 7, dest, 5);
    tmp = memcmp(dest, "Hello WHello", 11);
    cr_assert_eq(tmp, 0);
}

Test(memmove, negative_overlap)
{
    char *src = "Hello World";
    char dest[12];
    int tmp;

    my_memmove(dest, src, 12);
    my_memmove(dest, dest + 5, 5);
    tmp = memcmp(dest, " Worl World", 7);
    cr_assert_eq(tmp, 0);
}

Test(memmove, negative_overlap_2)
{
    char *src = "Hello World";
    char dest[12];
    int tmp;

    my_memmove(dest, src, 12);
    my_memmove(dest, dest + 1, 0);
    tmp = memcmp(dest, "Hello World", 12);
    cr_assert_eq(tmp, 0);
}