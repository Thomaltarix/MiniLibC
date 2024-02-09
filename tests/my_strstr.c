/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** my_strstr
*/

#include <dlfcn.h>
#include <stdio.h>

char *my_strstr(const char *haystack, const char *needle)
{
    void *handle;
    char *(*function)(const char *, const char *);
    char *error;
    char *result;

    handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return NULL;
    };
    function = dlsym(handle, "strstr");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return NULL;
    }
    result = function(haystack, needle);
    dlclose(handle);
    return result;
}