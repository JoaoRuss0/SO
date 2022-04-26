#include <stdio.h>
#include <string.h>
#include "conta_letra.h"
#include "debug.h"

int main (int argc, char const *argv[]) {
    if (argc != 3) {
        ERROR(1, "Too many or too few inputs, one character and one word must be supplied.\nExample: ./conta_letra a banana");
    }

    if (strlen(argv[1]) != 1) {
        ERROR(2, "Provided character is too long.");
    }

    int count = count_character_in_word(argv[1][0], argv[2]);

    fprintf(stdout , "The character '%c' appears %d times in '%s'.\n", argv[1][0], count, argv[2]);

    return 0;
}