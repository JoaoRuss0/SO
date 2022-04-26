#include <string.h>
#include <ctype.h>

#include "string_utils.h"

int is_vowel (char character) {
    switch (tolower(character)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
    }
    return 0;
}

int is_consonant (char character) {
    if (!is_vowel(character)) {
        character = tolower(character);
        if (!(character < 'a' || character > 'z')) {
            return 1;
        }
    }

    return 0;
}

int count_vowels (const char *string) {
    int count = 0;

    for (int i = 0; i < strlen(string); ++i) {
        count += is_vowel(string[i]);
    }

    return count;
}

int count_consonants (const char *string) {
    int count = 0;

    for (int i = 0; i < strlen(string); ++i) {
        count += is_consonant(string[i]);
    }

    return count;
}
