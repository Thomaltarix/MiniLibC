/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** strlen
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "functions.h"

int my_strlen(char *str)
{
    void *handle;
    int (*function)(char *);
    char *error;
    int result;

    handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return -1;
    };
    function = dlsym(handle, "strlen");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return -2;
    }
    result = function(str);
    dlclose(handle);
    return result;
}

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(strlen, empty_string, .init = redirect_all_std)
{
    char *test = "";
    int my_result;
    size_t result;

    my_result = my_strlen(test);
    result = strlen(test);
    cr_assert_eq(my_result, result);
}

Test(strlen, simple_sentence, .init = redirect_all_std)
{
    char *test = "Hello, World!";
    int my_result;
    size_t result;

    my_result = my_strlen(test);
    result = strlen(test);
    cr_assert_eq(my_result, result);
}

Test(strlen, long_sentence, .init = redirect_all_std)
{
    char *test = "lorem ipsum dolor sit amet, consectetur adipiscing elit.\
    sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\
    Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi\
    ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit\
    in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur\
    sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt\
    mollit anim id est laborum.";
    int my_result;
    size_t result;

    my_result = my_strlen(test);
    result = strlen(test);
    cr_assert_eq(my_result, result);
}
