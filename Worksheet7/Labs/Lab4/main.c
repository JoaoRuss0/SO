#include <stdio.h>

#include "debug.h"

#define ERR_IO 1

int main(void) {
    FILE *fptr = NULL;
    char *nome_ficheiro = "dados.txt";

    fptr = fopen(nome_ficheiro, "r");
    if (fptr == NULL) {
        ERROR(ERR_IO, "Erro ao abrir o ficheiro para leitura");
    }

    int idade, numero_entradas;
    float altura;
    char nome[40];
    float soma;
    numero_entradas = 0;
    soma = 0;

    while (fscanf(fptr, "%s %d %f", nome, &idade, &altura) == 3) {
        soma += idade;
        numero_entradas++;
        printf("Entrada %d: Nome = %s Idade = %d Altura = %f\n",
               numero_entradas, nome, idade, altura);
    }

    if (!feof(fptr)) {
        ERROR(ERR_IO, "%s: Erro de leitura\n", nome_ficheiro);
    } else if (numero_entradas > 0) {
        printf("Media das idades: %f\n", soma / numero_entradas);
    }

    fclose(fptr);
    
    return 0;
}
