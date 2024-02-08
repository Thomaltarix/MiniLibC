/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** my_strlen
*/

#include <dlfcn.h>
#include <stdio.h>

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