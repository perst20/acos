//
// Created by kimigaev on 30.11.2021.
//

#include "cstring_tools.h"

void EndStrip(char *str) {
    char * last_sym = str;
    for (char * c = str; *c != '\0'; ++c) {
        switch (*c) {
            case ' ':
            case '\n':
            case '\t':
                break;
            default:
                last_sym = c;
                break;
        }
    }
    for (char * c = last_sym + 1; *c != '\0'; ++c) {
        *c = '\0';
    }
}

void RandomString(char *str, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        int first = 32, last = 126;
        if (i == 0 || i == n - 1) {
            first = 33;
        }
        str[i] = (char)(rand() % (last - first + 1) + first);
    }
    str[n] = '\0';
}
