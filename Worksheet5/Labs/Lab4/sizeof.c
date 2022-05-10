#include <stdio.h>

int main(void) {
    char *ptr = NULL;

    printf("sizeof(*ptr)=%zu (size of the variable the pointer points to, char, which is 1 byte)\n", sizeof(*ptr));
    printf("sizeof(ptr) =%zu (size of a pointer)\n", sizeof(ptr));

    return 0;
}
