/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** my_memset
*/

#include <dlfcn.h>
#include <stdio.h>

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