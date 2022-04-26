#include <stdio.h>

#include "funcoes.h"
#include "funcoes_aux.h"

int main(void) {
    float numA, numB;
    printf("Introduza um numero: ");
    scanf("%f", &numA);
    printf("Introduza outro numero: ");
    scanf("%f", &numB);
    printf("\nA soma = %f", soma(numA, numB));
    printf("\ndiv_e_soma = %f", div_e_soma(numA, numB));
    printf("\nA raiz da div_e_soma = %f\n", raiz(div_e_soma(numA, numB)));
    return 0;
}
