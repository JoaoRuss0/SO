#include <stdio.h>

#include "string_utils.h"

int main (int argc, char const *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Insufficient number of parameters. At least 1 string is required.\n");
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        fprintf(stdout, "%s: %d vowels, %d consonants\n", argv[i], count_vowels(argv[i]), count_consonants(argv[i]));
    }

    return 0;
}

