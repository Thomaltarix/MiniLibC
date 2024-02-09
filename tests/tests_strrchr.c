/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strrchr
*/

#include "functions.h"

char *my_strrchr(const char *s, int c)
{
    void *handle;
    char *(*function)(const char *, int);
    char *error;
    char *result;

    handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return NULL;
    };
    function = dlsym(handle, "strrchr");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return NULL;
    }
    result = function(s, c);
    dlclose(handle);
    return result;
}

Test(my_strrchr, simple_strrchr, .init = redirect_all_std)
{
    char *test = "Hello!";
    char *my_result;
    char *result;

    my_result = my_strrchr(test, 'l');
    result = strrchr(test, 'l');
    cr_assert_str_eq(my_result, result);
}

Test(my_strrchr, long_strrchr, .init = redirect_all_std)
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

    my_result = my_strrchr(test, 'a');
    result = strrchr(test, 'a');
    cr_assert_str_eq(my_result, result);
}

Test(my_strrchr, not_found_strrchr, .init = redirect_all_std)
{
    char *test = "Hello, World!";
    char *my_result;
    char *result;

    my_result = my_strrchr(test, 'z');
    cr_assert_eq(my_result, NULL);
}

Test(my_strrchr, empty_strrchr, .init = redirect_all_std)
{
    char *test = "";
    char *my_result;
    char *result;

    my_result = my_strrchr(test, 'z');
    result = strrchr(test, 'z');
    cr_assert_eq(my_result, result);
}