/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** my_strchr
*/

#include <dlfcn.h>
#include <stdio.h>

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