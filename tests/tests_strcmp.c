/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strcmp
*/

#include "functions.h"

int my_strcmp(const char *s1, const char *s2)
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
    function = dlsym(handle, "strcmp");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return 84;
    }
    result = function(s1, s2);
    dlclose(handle);
    return result;
}

Test(my_strcmp, simple_sentence, .init = redirect_all_std)
{
    char *s1 = "Hello, world!";
    char *s2 = "Hello, world!";
    int my_result = my_strcmp(s1, s2);
    int result = strcmp(s1, s2);

    cr_assert_eq(my_result, result);
}

Test(my_strcmp, no_sentence, .init = redirect_all_std)
{
    char *s1 = "";
    char *s2 = "";
    int my_result = my_strcmp(s1, s2);
    int result = strcmp(s1, s2);

    cr_assert_eq(my_result, result);
}

Test(my_strcmp, different_sentence, .init = redirect_all_std)
{
    char *s1 = "Hello, world!";
    char *s2 = "Hello, world";
    int my_result = my_strcmp(s1, s2);
    int result = strcmp(s1, s2);

    cr_assert_eq(my_result, result);
}

Test(my_strcmp, one_sentence_empty, .init = redirect_all_std)
{
    char *s1 = "Hello, world!";
    char *s2 = "";
    int my_result = my_strcmp(s1, s2);
    int result = strcmp(s1, s2);

    cr_assert_eq(my_result, result);
}

Test(my_strcmp, one_sentence_empty2, .init = redirect_all_std)
{
    char *s1 = "";
    char *s2 = "Hello, world!";
    int my_result = my_strcmp(s1, s2);
    int result = strcmp(s1, s2);

    cr_assert_eq(my_result, result);
}