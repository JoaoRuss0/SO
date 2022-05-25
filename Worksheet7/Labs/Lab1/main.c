#include <stdio.h>
#include <string.h>
#include "debug.h"

#define MAX 100
#define ERR_IO 1

int main(void) {
    FILE *fptr = NULL;
    char buffer[MAX], *text;

    fptr = fopen("log.txt", "a");
    if (fptr == NULL)
        ERROR(ERR_IO, "Erro ao abrir o ficheiro para acrescimo");

    text = fgets(buffer, MAX, stdin);
    while (text != NULL && strcmp(buffer, "fim\n") != 0) {
        if (fputs(buffer, fptr) == EOF) {
            WARNING("Erro de escrita\n");
            break;
        }
        text = fgets(buffer, MAX, stdin);
    }
    fclose(fptr);
    return 0;
}
