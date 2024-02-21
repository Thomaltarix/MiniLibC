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
    cr_assert_str_eq(my_strrchr(test, 'H'), strrchr(test, 'H'));
}

Test(my_strrchr, simple_strrchr2, .init = redirect_all_std)
{
    char *test = "Hello!";
    cr_assert_str_eq(my_strrchr(test, 'l'), strrchr(test, 'l'));
}

Test(my_strrchr, simple_strrchr3, .init = redirect_all_std)
{
    char *test = "Hello!";
    cr_assert_str_eq(my_strrchr(test, 'o'), strrchr(test, 'o'));
}

Test(my_strrchr, no_solution, .init = redirect_all_std)
{
    char *test = "Hello!";
    cr_assert_eq(my_strrchr(test, 'a'), strrchr(test, 'a'));
}

Test(my_strrchr, empty_str, .init = redirect_all_std)
{
    char *test = "";
    cr_assert_eq(my_strrchr(test, 'a'), strrchr(test, 'a'));
}

Test(my_strrchr, empty_str2, .init = redirect_all_std)
{
    char *test = "";
    cr_assert_str_eq(my_strrchr(test, '\0'), strrchr(test, '\0'));
}

Test(my_strrchr, empty_source, .init = redirect_all_std)
{
    char *test = "\0";
    cr_assert_eq(my_strrchr(test, 'a'), strrchr(test, 'a'));
}

Test(my_strrchr, empty_source2, .init = redirect_all_std)
{
    char *test = "\0";
    cr_assert_str_eq(my_strrchr(test, '\0'), strrchr(test, '\0'));
}

Test(my_strrchr, empty_source3, .init = redirect_all_std)
{
    char *test = "Hello, world!";
    cr_assert_str_eq(my_strrchr(test, '\0'), strrchr(test, '\0'));
}
