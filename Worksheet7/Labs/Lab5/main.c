#include <stdio.h>
#include "debug.h"

typedef enum { informatica, informatica_saude } curso_t;

typedef struct {
    int dia, mes, ano;
} data_t;

typedef struct {
    char nome[25];
    long numero;
    data_t inscricao;
    curso_t curso;
} aluno_t;

#define ERR_IO 1

int main(void) {
    FILE *fptr = NULL;

    fptr = fopen("dados.dat", "wb");
    if (fptr == NULL)
        ERROR(ERR_IO, "Erro ao abrir o ficheiro para escrita");

    aluno_t dados[3] = {
        {"Pedro Ribeiro", 20085672, {10, 10, 1995}, informatica},
        {"Luisa Santos", 20097823, {25, 9, 1996}, informatica_saude},
        {"Helder Batista", 20087837, {16, 3, 1994}, informatica_saude}};

    if (fwrite(dados, sizeof(aluno_t), 3, fptr) != 3) {
        ERROR(ERR_IO, "Erro ao escrever para o ficheiro");
    }

    fclose(fptr);
    return 0;
}
