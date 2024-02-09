/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** functions
*/

#pragma once

int my_strlen(char *str);
char *my_strchr(const char *s, int c);
char *my_strrchr(const char *s, int c);
void *my_memset(void *s, int c, size_t n);

void redirect_all_std(void);