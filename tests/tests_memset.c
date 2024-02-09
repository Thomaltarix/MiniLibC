/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_memset
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "functions.h"

void *my_memset(void *s, int c, size_t n)
{
    void *handle;
    void *(*function)(void *, int, size_t);
    char *error;
    void *result;

    handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return NULL;
    };
    function = dlsym(handle, "memset");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return NULL;
    }
    result = function(s, c, n);
    dlclose(handle);
    return result;
}

Test(memset, simple_sentence, .init = redirect_all_std)
{
    char test[14] = "Hello, World!";
    void *my_result;
    void *result;
    int tmp;

    my_result = my_memset(test, 'a', 5);
    result = memset(test, 'a', 5);
    tmp = memcmp(my_result, result, 5);
    cr_assert_eq(tmp, 0);
}

Test(memset, size_0, .init = redirect_all_std)
{
    char test[14] = "Hello, World!";
    void *my_result;
    void *result;
    int tmp;

    my_result = my_memset(test, 'a', 0);
    result = memset(test, 'a', 0);
    tmp = memcmp(my_result, result, 0);
    cr_assert_eq(tmp, 0);
}

Test(memset, full_sentence, .init = redirect_all_std)
{
    char test[14] = "Hello, World!";
    void *my_result;
    void *result;
    int tmp;

    my_result = my_memset(test, 'a', 13);
    result = memset(test, 'a', 1);
    tmp = memcmp(my_result, result, 13);
    cr_assert_eq(tmp, 0);
}

Test(memset, no_sentence, .init = redirect_all_std)
{
    char test[0] = "";
    void *my_result;
    void *result;
    int tmp;

    my_result = my_memset(test, 'a', 1);
    result = memset(test, 'a', 1);
    tmp = memcmp(my_result, result, 1);
    cr_assert_eq(tmp, 0);
}