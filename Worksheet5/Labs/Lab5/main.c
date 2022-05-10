#include <stdio.h>

int main(void) {
    long *vect_not_initialized = NULL;
    unsigned int i = 0;

    for (i = 0; i < 10; i++)
        vect_not_initialized[i] = i * 100;
    return 0;
}
