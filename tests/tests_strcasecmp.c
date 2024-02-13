/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strcmp
*/

#include "functions.h"

int my_strcasecmp(const char *s1, const char *s2)
{
    void *handle;
    int (*function)(const char *, const char *);
    char *error;
    int result;

    handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 84;
    };
    function = dlsym(handle, "strcasecmp");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return 84;
    }
    result = function(s1, s2);
    dlclose(handle);
    return result;
}

Test(my_strcasecmp, no_string)
{
    char *s1 = "";
    char *s2 = "";
    int my_result = my_strcasecmp(s1, s2);
    int result = strcasecmp(s1, s2);

    cr_assert_eq(my_result, result);
}

Test(my_strcasecmp, empty_string_1)
{
    char *s1 = "";
    char *s2 = "Hello, world!";
    int my_result = my_strcasecmp(s1, s2);
    int result = strcasecmp(s1, s2);

    cr_assert_eq(my_result, result);
}

Test(my_strcasecmp, empty_string_2)
{
    char *s1 = "Hello, world!";
    char *s2 = "";
    int my_result = my_strcasecmp(s1, s2);
    int result = strcasecmp(s1, s2);

    cr_assert_eq(my_result, result);
}

Test(my_strcasecmp, simple_string)
{
    char *s1 = "H";
    char *s2 = "H";
    int my_result = my_strcasecmp(s1, s2);
    int result = strcasecmp(s1, s2);

    cr_assert_eq(my_result, result);
}

Test(my_strcasecmp, different_string)
{
    char *s1 = "Hello, world!";
    char *s2 = "Hello, world!";
    int my_result = my_strcasecmp(s1, s2);
    int result = strcasecmp(s1, s2);

    cr_assert_eq(my_result, result);
}

Test(my_strcasecmp, string_diff_case)
{
    char *s1 = "Hello, world!";
    char *s2 = "HELLO, WORLD!";
    int my_result = my_strcasecmp(s1, s2);
    int result = strcasecmp(s1, s2);

    cr_assert_eq(my_result, result);
}

Test(my_strcasecmp, string_diff_case2)
{
    char *s1 = "HeLlO, WoRlD!";
    char *s2 = "HELLO, WORLD!";
    int my_result = my_strcasecmp(s1, s2);
    int result = strcasecmp(s1, s2);

    cr_assert_eq(my_result, result);
}
