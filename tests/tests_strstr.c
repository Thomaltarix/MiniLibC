/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strstr
*/

#include "functions.h"

char *my_strstr(const char *haystack, const char *needle)
{
    void *handle;
    char *(*my_strstr)(const char *, const char *);
    char *error;
    char *result;

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
    result = my_strstr(haystack, needle);
    dlclose(handle);
    return result;
}

Test(strstr, simple_sentence)
{
    char *test = "Hello, World!";
    char *my_result;
    char *result;

    my_result = my_strstr(test, "World");
    result = strstr(test, "World");
    cr_assert_eq(my_result, result);
}

Test(strstr, long_sentence)
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

    my_result = my_strstr(test, "adipiscing");
    result = strstr(test, "adipiscing");
    cr_assert_eq(my_result, result);
}

Test(strstr, not_found)
{
    char *test = "Hello, World!";
    char *my_result;
    char *result;

    my_result = my_strstr(test, "test");
    result = strstr(test, "test");
    cr_assert_eq(my_result, result);
}

Test(strstr, empty_needle)
{
    char *test = "Hello, World!";
    char *my_result;
    char *result;

    my_result = my_strstr(test, "");
    result = strstr(test, "");
    cr_assert_eq(my_result, result);
}

Test(strstr, empty_string)
{
    char *test = "";
    char *my_result;
    char *result;

    my_result = my_strstr(test, "z");
    result = strstr(test, "z");
    cr_assert_eq(my_result, result);
}

Test(strstr, zero_ended_string)
{
    char *test = "Hello, World!\0";
    char *my_result;
    char *result;

    my_result = my_strstr(test, "World");
    result = strstr(test, "World");
    cr_assert_eq(my_result, result);
}

Test(strstr, zero_ended_string_only)
{
    char *test = "";
    char *my_result;
    char *result;

    my_result = my_strstr(test, "\0");
    result = strstr(test, "\0");
    cr_assert_eq(my_result, result);
}

Test(strstr, zero_ended_string_needle)
{
    char *test = "Hello, World!\0";
    char *my_result;
    char *result;

    my_result = my_strstr(test, "\0");
    result = strstr(test, "\0");
    cr_assert_eq(my_result, result);
}
