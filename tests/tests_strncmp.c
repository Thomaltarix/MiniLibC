/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strcmp
*/

#include "functions.h"

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    void *handle;
    int (*function)(const char *, const char *, size_t);
    char *error;
    int result;

    handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 84;
    };
    function = dlsym(handle, "strncmp");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return 84;
    }
    result = function(s1, s2, n);
    dlclose(handle);
    return result;
}

Test(my_strncmp, simple_sentence, .init = redirect_all_std)
{
    char *s1 = "Hello, world!";
    char *s2 = "Hello, world!";
    int my_result = my_strncmp(s1, s2, 13);
    int result = strncmp(s1, s2, 13);

    cr_assert_eq(my_result, result);
}

Test(my_strncmp, no_string, .init = redirect_all_std)
{
    char *s1 = "";
    char *s2 = "";
    int my_result = my_strncmp(s1, s2, 0);
    int result = strncmp(s1, s2, 0);

    cr_assert_eq(my_result, result);
}

Test(my_strncmp, no_string2, .init = redirect_all_std)
{
    char *s1 = "";
    char *s2 = "";
    char s3[100];
    char s4[100];

    sprintf(s3, "%d", my_strncmp(s1, s2, 10));
    sprintf(s4, "%d", strncmp(s1, s2, 10));
    cr_assert_str_eq(s3, s4);
}

Test(my_strncmp, empty_string, .init = redirect_all_std)
{
    char *s1 = "g";
    char *s2 = "g";
    char s3[100];
    char s4[100];

    sprintf(s3, "%d", my_strncmp(s1, s2, 2));
    sprintf(s4, "%d", strncmp(s1, s2, 2));
    cr_assert_str_eq(s3, s4);
}

Test(my_strncmp, different_string, .init = redirect_all_std)
{
    char *s1 = "!Hello, world!";
    char *s2 = ";Hello, world!";
    char s3[100];
    char s4[100];

    sprintf(s3, "%d", my_strncmp(s1, s2, 5));
    sprintf(s4, "%d", strncmp(s1, s2, 5));
    cr_assert_str_eq(s3, s4);
}

Test(my_strncmp, different_string2, .init = redirect_all_std)
{
    char *s1 = "Hell";
    char *s2 = "Hell!";
    char s3[100];
    char s4[100];

    sprintf(s3, "%d", my_strncmp(s1, s2, 10));
    sprintf(s4, "%d", strncmp(s1, s2, 10));
    cr_assert_str_eq(s3, s4);
}

Test(my_strncmp, different_string3, .init = redirect_all_std)
{
    char *s1 = "Hello, world!";
    char *s2 = "Hello, world";
    char s3[100];
    char s4[100];

    sprintf(s3, "%d", my_strncmp(s1, s2, 13));
    sprintf(s4, "%d", strncmp(s1, s2, 13));
    cr_assert_str_eq(s3, s4);
}

Test(my_strncmp, one_string_empty, .init = redirect_all_std)
{
    char *s1 = "Hello, world!";
    char *s2 = "";
    char s3[100];
    char s4[100];

    sprintf(s3, "%d", my_strncmp(s1, s2, 13));
    sprintf(s4, "%d", strncmp(s1, s2, 13));
    cr_assert_str_eq(s3, s4);
}

Test(my_strncmp, one_string_empty2, .init = redirect_all_std)
{
    char *s1 = "";
    char *s2 = "Hello, world!";
    char s3[100];
    char s4[100];

    sprintf(s3, "%d", my_strncmp(s1, s2, 13));
    sprintf(s4, "%d", strncmp(s1, s2, 13));
    cr_assert_str_eq(s3, s4);
}

Test(my_strncmp, one_string_empty3, .init = redirect_all_std)
{
    char *s1 = "Hello, world!";
    char *s2 = "Hello, world!";
    char s3[100];
    char s4[100];

    sprintf(s3, "%d", my_strncmp(s1, s2, 3));
    sprintf(s4, "%d", strncmp(s1, s2, 3));
    cr_assert_str_eq(s3, s4);
}