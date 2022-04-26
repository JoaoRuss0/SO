#include <stdio.h>
#include <string.h>

#include "string_utils.h"

int main (int argc, const char *argv[]) {
    if (argc == 1) {
        fprintf(stdout, "Usage: ./vowels_v3 [--vowels | --consonants | --leet] string1 [[string 2]...]\n");
        return 1;
    }

    // Check if an option was passed
    if (!(argv[1][0] == '-' && argv[1][1] == '-')) {
        // Print everything about each word
        for (int i = 1; i < argc; ++i) {
            char leet_string[strlen(argv[i])];
            strcpy(leet_string, argv[i]);
            string_to_leet(argv[i], leet_string);

            fprintf(stdout, "%s: %d consonants, %d consonants, %s [basic leet]\n", argv[i], count_vowels(argv[i]), count_consonants(argv[i]), leet_string);
        }

        return 0;
    }

    // Option was passed but there are no more arguments
    if(argc == 2) {
        printf("Usage: ./vowels_v3 [--vowels | --consonants | --leet] string1 [[string 2]...]\n");
        return 2;
    }

    if (strcmp(argv[1], "--vowels") == 0) {
        for (int i = 2; i < argc; ++i) {
            fprintf(stdout, "%s: %d vowels\n", argv[i], count_vowels(argv[i]));
        }
    }
    else if (strcmp(argv[1], "--consonants") == 0) {
        for (int i = 2; i < argc; ++i) {
            fprintf(stdout, "%s: %d consonants\n", argv[i], count_consonants(argv[i]));
        }
    }
    else if (strcmp(argv[1], "--leet") == 0) {
        for (int i = 2; i < argc; ++i) {
            char leet_string[strlen(argv[i])];
            strcpy(leet_string, argv[i]);
            string_to_leet(argv[i], leet_string);

            fprintf(stdout, "%s: %s [basic leet]\n", argv[i], leet_string);
        }
    } // An option was passed but it is invalid
    else {
        fprintf(stderr, "'%s' is not an option. Available options are '--vowels', '--consonants' '--leet'.\n", argv[1]);
    }

    return 0;
}

