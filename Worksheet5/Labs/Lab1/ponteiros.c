#include <stdio.h>

int main(void) {
    int *iptr = NULL, q = 20;
    iptr = &q;

    /* Escreve o valor 20 */
    printf("%d\n", q);
    /* Escreve o valor apontado por iptr => o valor 20 */
    printf("%d\n", *iptr);
    printf("Endereço da variável q = %p\n", (void *)&q);
    printf("Endereço armazenado em iptr = %p\n", (void *)iptr);
    printf("Endereço da variável iptr = %p\n", (void *)&iptr);
    return 0;
}
