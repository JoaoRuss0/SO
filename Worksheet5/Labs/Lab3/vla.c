#include <stdio.h>
#include <stdlib.h>
/*
 * compile: gcc -std=c99 -Wall -W vla.c -o vla.exe
 */
void vla_func(int num_elems) {
    float vla_vector[num_elems];

    printf("Using VLA with %d elements\n", num_elems);
    int i;
    for (i = 0; i < num_elems; i++) {
        vla_vector[i] = 1.0 * i;
    }
    /* Print 1st and last element of array */
    printf("[0] => %.2f\t", vla_vector[0]);
    printf("[%d] => %.2f\n", num_elems - 1, vla_vector[num_elems - 1]);
}

int main(int argc, const char *argv[]) {
    int num_elms;
    if (argc == 1) {
        fprintf(stderr, "ERROR: no arguments given\n");
        fprintf(stderr, "%s <num_elements>\n", argv[0]);
        exit(1);
    }
    num_elms = atoi(argv[1]);
    if (num_elms <= 0) {
        fprintf(stderr,
                "ERROR: invalid number of elements %d "
                "(num_elements needs to be positive)\n",
                num_elms);
        exit(2);
    }
    vla_func(num_elms);
    return 0;
}
