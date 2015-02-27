#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(const int argc, const char* const argv[]) {
    int newline;
    if (*++argv && !strcmp(*argv, "-n")) {
        newline = 0;
        ++argv;
    } else {
        newline = 1;
    }
    while (*argv) {
        fputs(*argv, stdout);
        if (*++argv != 0) {
            putchar(' ');
        }
    }
    if (newline) {
        putchar('\n');
    }
    return EXIT_SUCCESS;
}

