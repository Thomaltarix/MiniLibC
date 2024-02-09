/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strstr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "functions.h"

Test(strstr, simple_sentence, .init = redirect_all_std)
{
    char *test = "Hello, World!";
    char *my_result;
    char *result;

    my_result = my_strstr(test, "World");
    result = strstr(test, "World");
    cr_assert_str_eq(my_result, result);
}
