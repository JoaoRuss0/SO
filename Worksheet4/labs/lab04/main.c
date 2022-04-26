#include <stdio.h>

#include "funcoes.h"
#include "funcoesAux.h"

int main(void) {
    float numA, numB;
    printf("Introduza um numero: ");
    scanf("%f", &numA);
    printf("Introduza outro numero: ");
    scanf("%f", &numB);
    printf("\nA soma = %f", soma(numA, numB));
    printf("\ndiv_e_soma = %f\n", div_e_soma(numA, numB));
    return 0;
}
