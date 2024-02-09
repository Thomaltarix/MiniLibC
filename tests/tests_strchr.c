/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strchr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "functions.h"

char *my_strchr(const char *s, int c)
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
    function = dlsym(handle, "strchr");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return NULL;
    }
    result = function(s, c);
    dlclose(handle);
    return result;
}

Test(strchr, simple_sentence, .init = redirect_all_std)
{
    char *test = "Hello, World!";
    char *my_result;
    char *result;

    my_result = my_strchr(test, 'W');
    result = strchr(test, 'W');
    cr_assert_eq(my_result, result);
}

Test(strchr, long_sentence, .init = redirect_all_std)
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

    my_result = my_strchr(test, 'a');
    result = strchr(test, 'a');
    cr_assert_eq(my_result, result);
}

Test(strchr, not_found, .init = redirect_all_std)
{
    char *test = "Hello, World!";
    char *my_result;
    char *result;

    my_result = my_strchr(test, 'z');
    cr_assert_eq(my_result, NULL);
}

Test(strchr, empty_string, .init = redirect_all_std)
{
    char *test = "";
    char *my_result;
    char *result;

    my_result = my_strchr(test, 'z');
    cr_assert_eq(my_result, NULL);
}
