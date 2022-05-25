#include <stdio.h>
#include "debug.h"

#define ERR_IO 1

typedef struct {
    char nome[40];
    long numero;
} aluno_t;

int main(void) {
    FILE *fptr = NULL;
    aluno_t dados[2] = {{"Pedro", 22}, {"Luisa", 20}};
    int i;

    fptr = fopen("dados.txt", "w"); /* "wt" em Windows */
    if (fptr == NULL)
        ERROR(ERR_IO, "Erro ao abrir o ficheiro para escrita");

    for (i = 0; i < 2; i++) {
        if (fprintf(fptr, "%s %ld\n", dados[i].nome, dados[i].numero) == EOF) {
            ERROR(1, "Erro de escrita");
        }
    }
    fclose(fptr);

    return 0;
}
