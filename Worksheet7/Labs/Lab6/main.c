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

    fptr = fopen("dados.dat", "rb");
    if (fptr == NULL)
        ERROR(ERR_IO, "Erro ao abrir o ficheiro para leitura");

    /* Primeiro calcula-se o número de elementos do ficheiro
             O número de elementos é dado por:
                    tamanho do ficheiro / sizeof(tamanho de cada elemento)
    */
    int nelem, pos;
    aluno_t aluno;

    fseek(fptr, 0L, SEEK_END);
    nelem = ftell(fptr) / sizeof(aluno_t);

    printf("Qual a ficha que deseja ver? (0-%d)\n", nelem - 1);
    scanf("%d", &pos);

    while (pos >= 0 && pos < nelem) {
        /* Posiciona o ponteiro na ficha desejada. Nota: a ficha
                 nº pos está na posição	pos*sizeof(aluno_t)
        */
        fseek(fptr, pos * sizeof(aluno_t), SEEK_SET);

        if (fread(&aluno, sizeof(aluno_t), 1, fptr) != 1)
            ERROR(ERR_IO, "Erro de escrita");

        printf("Ficha nº %d:\n", pos);
        printf("Nome: %s\nNumero: %ld\n", aluno.nome, aluno.numero);

        /* Pede próxima ficha */
        printf("Qual a ficha que deseja ver? (0-%d)\n", nelem - 1);
        scanf("%d", &pos);
    }
    fclose(fptr);
    return 0;
}
