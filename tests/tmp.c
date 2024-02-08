/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tmp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// Test(strlen, simple_sentence, .init = redirect_all_std)
// {
//     void *handle;
//     size_t (*my_strlen)(char *);
//     char *error;
//     char *test = "Hello, World!";
//     size_t my_result;
//     size_t result;

//     handle = dlopen("./libasm.so", RTLD_LAZY);
//     if (!handle) {
//         fprintf(stderr, "%s\n", dlerror());
//         return;
//     }
//     my_strlen = dlsym(handle, "strlen");
//     if ((error = dlerror()) != NULL) {
//         fprintf(stderr, "%s\n", error);
//         return;
//     }
//     my_result = my_strlen(test);
//     result = strlen(test);
//     cr_assert_eq(my_result, result);
// }

