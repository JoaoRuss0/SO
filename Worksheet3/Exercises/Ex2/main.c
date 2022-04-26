#include <stdio.h>
#include <string.h>

#include "string_utils.h"

int count_vowels (const char *string);

int main (int argc, char const *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Insufficient number of parameters. At least 1 string is required.\n");
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        fprintf(stdout, "%s: %d vowels\n", argv[i], count_vowels(argv[i]));
    }

    return 0;
}

int count_vowels (const char *string) {
    int count = 0;

    for (int i = 0; i < strlen(string); ++i) {
        switch (string[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                count++;
                break;
            default:
                continue;
        }
    }

    return count;
}
