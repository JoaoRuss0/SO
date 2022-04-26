#include <string.h>
#include "conta_letra.h"

int count_character_in_word (const char character, const char *string) {
    int count = 0;

    for (size_t i = 0; i < strlen(string); i++) {
        if(string[i] == character) {
            count++;
        }
    }

    return count;
}
