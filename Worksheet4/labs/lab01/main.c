#include <stdio.h>

#include "string_utils.h"

int main(int argc, char const *argv[]) {
    int i;
    for (i = 1; i < argc; ++i) {
        printf("%s: %d vowels, %d consonants\n", argv[i], count_vowels(argv[i]),
               count_consonants(argv[i]));
    }
    return 0;
}
