/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strcspn
*/

#include "functions.h"

size_t my_strcspn(const char *s, const char *reject)
{
    void *handle;
    size_t (*my_strcspn)(const char *, const char *);
    char *error;
    size_t result;

    handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 0;
    }
    my_strcspn = dlsym(handle, "strcspn");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return 0;
    }
    result = my_strcspn(s, reject);
    dlclose(handle);
    return result;
}

Test(strcspn, simple_string)
{
    char *test = "Hello, World!";
    size_t my_result;
    size_t result;

    my_result = my_strcspn(test, "World");
    result = strcspn(test, "World");
    cr_assert_eq(my_result, result);
}

Test(strcspn, simple_string2)
{
    char *test = "Hello, World!";
    size_t my_result;
    size_t result;

    my_result = my_strcspn(test, "o");
    result = strcspn(test, "o");
    cr_assert_eq(my_result, result);
}

Test(strcspn, simple_string3)
{
    char *test = "Hello, World!";
    size_t my_result;
    size_t result;

    my_result = my_strcspn(test, "zwh");
    result = strcspn(test, "zwh");
    cr_assert_eq(my_result, result);
}

Test(strcspn, no_reject)
{
    char *test = "Hello, World!";
    size_t my_result;
    size_t result;

    my_result = my_strcspn(test, "");
    result = strcspn(test, "");
    cr_assert_eq(my_result, result);
}

Test(strcspn, no_string)
{
    char *test = "";
    size_t my_result;
    size_t result;

    my_result = my_strcspn(test, "World");
    result = strcspn(test, "World");
    cr_assert_eq(my_result, result);
}

Test(strcspn, no_string_no_reject)
{
    char *test = "";
    size_t my_result;
    size_t result;

    my_result = my_strcspn(test, "");
    result = strcspn(test, "");
    cr_assert_eq(my_result, result);
}

Test(strcspn, zero_ended_string)
{
    char *test = "Hello, World!\0";
    size_t my_result;
    size_t result;

    my_result = my_strcspn(test, "World");
    result = strcspn(test, "World");
    cr_assert_eq(my_result, result);
}

Test(strcspn, zero_ended_string2)
{
    char *test = "Hello, World!\0";
    size_t my_result;
    size_t result;

    my_result = my_strcspn(test, "o");
    result = strcspn(test, "o");
    cr_assert_eq(my_result, result);
}

Test(strcspn, zero_ended_reject)
{
    char *test = "Hello, World!";
    size_t my_result;
    size_t result;

    my_result = my_strcspn(test, "World\0");
    result = strcspn(test, "World\0");
    cr_assert_eq(my_result, result);
}

Test(strcspn, zero_ended_reject2)
{
    char *test = "Hello, World!";
    size_t my_result;
    size_t result;

    my_result = my_strcspn(test, "o\0");
    result = strcspn(test, "o\0");
    cr_assert_eq(my_result, result);
}

Test(strcspn, zero_ended_string_reject)
{
    char *test = "Hello, World!\0";
    size_t my_result;
    size_t result;

    my_result = my_strcspn(test, "\0");
    result = strcspn(test, "\0");
    cr_assert_eq(my_result, result);
}

Test(strcspn, zero_ended_string_reject2)
{
    char *test = "\0";
    size_t my_result;
    size_t result;

    my_result = my_strcspn(test, "\0");
    result = strcspn(test, "\0");
    cr_assert_eq(my_result, result);
}
