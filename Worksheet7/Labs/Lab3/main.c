#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "debug.h"
#define ERR_ARGS 1
#define ERR_IO 2

int conta_digitos(char *nome_ficheiro);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Utilizacao: %s <ficheiro>\n", argv[0]);
        exit(ERR_ARGS);
    }
    char *nome_ficheiro = argv[1];
    printf("Total de digitos no ficheiro %s: %d\n", nome_ficheiro,
           conta_digitos(nome_ficheiro));
    return 0;
}

int conta_digitos(char *nome_ficheiro) {
    FILE *fptr = NULL;

    fptr = fopen(nome_ficheiro, "r");
    if (fptr == NULL)
        ERROR(ERR_IO, "Erro ao abrir o ficheiro para leitura");

    int conta = 0;
    int ch;
    while ((ch = fgetc(fptr)) != EOF)
        if (isdigit(ch))
            conta++;

    /* Verifica se está no final do ficheiro. Se não está é porque existe um
     * erro de leitura */
    if (!feof(fptr)) {
        fprintf(stderr, "%s: Erro de leitura\n", nome_ficheiro);
        return -1;
    }

    fclose(fptr);
    return conta;
}
