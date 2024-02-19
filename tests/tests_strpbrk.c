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
    char *result;

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
    result = my_strpbrk(s, accept);
    dlclose(handle);
    return result;
}

Test(strpbrk, simple_sentence)
{
    char *test = "Hello, World!";
    char *my_result;
    char *result;

    my_result = my_strpbrk(test, "World");
    result = strpbrk(test, "World");
    cr_assert_eq(my_result, result);
}

Test(strpbrk, long_sentence)
{
    char *test = "lorem ipsum dolor sit amet, consectetur adipiscing elit.\
    sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\
    Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi\
    ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit\
    in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur\
    sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt\
    mollit anim id est laborum.";
    char *my_result;
    char *result;

    my_result = my_strpbrk(test, "ipsum");
    result = strpbrk(test, "ipsum");
    cr_assert_eq(my_result, result);
}

Test(strpbrk, not_found)
{
    char *test = "Hello, World!";
    char *my_result;
    char *result;

    my_result = my_strpbrk(test, "zwv.yx");
    result = strpbrk(test, "zwv.yx");
    cr_assert_eq(my_result, result);
}

Test(strpbrk, empty_string)
{
    char *test = "";
    char *my_result;
    char *result;

    my_result = my_strpbrk(test, "World");
    result = strpbrk(test, "World");
    cr_assert_eq(my_result, result);
}

Test(strpbrk, empty_accept)
{
    char *test = "Hello, World!";
    char *my_result;
    char *result;

    my_result = my_strpbrk(test, "");
    result = strpbrk(test, "");
    cr_assert_eq(my_result, result);
}

Test(strpbrk, empty_string_and_accept)
{
    char *test = "";
    char *my_result;
    char *result;

    my_result = my_strpbrk(test, "");
    result = strpbrk(test, "");
    cr_assert_eq(my_result, result);
}

Test(strpbrk, zero_ended_string)
{
    char *test = "Hello, World!\0";
    char *my_result;
    char *result;

    my_result = my_strpbrk(test, "World");
    result = strpbrk(test, "World");
    cr_assert_eq(my_result, result);
}

Test(strpbrk, zero_ended_string_only)
{
    char *test = "";
    char *my_result;
    char *result;

    my_result = my_strpbrk(test, "\0");
    result = strpbrk(test, "\0");
    cr_assert_eq(my_result, result);
}

Test(strpbrk, zero_ended_string_accept)
{
    char *test = "Hello, World!";
    char *my_result;
    char *result;

    my_result = my_strpbrk(test, "\0");
    result = strpbrk(test, "\0");
    cr_assert_eq(my_result, result);
}
