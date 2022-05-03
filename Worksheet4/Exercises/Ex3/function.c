#include <math.h>

#include "function.h"

int bytes_for_int(unsigned int max_value) {
    int count = 1;

    while (count < (int) sizeof(unsigned int)) {
        if (max_value <= (unsigned int) pow(2, count * 8) - 1) {
            break;
        }

        count++;
    }

    return count;
}