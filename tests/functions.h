/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** functions
*/

#pragma once

int my_strlen(char *str);
char *my_strchr(const char *s, int c);
char *my_strstr(const char *haystack, const char *needle);

void redirect_all_std(void);