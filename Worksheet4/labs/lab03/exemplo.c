#define _POSIX_SOURCE
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "debug.h"

int main(void) {
    int fd;
    char *file = "/etc/passwd";
    int a = 234, pid = 1;
    float b = 3.1415;

    printf("Exemplo do uso das funcoes de tratamento de erros\n");

#ifdef SHOW_DEBUG
    DEBUG("O valor de 'a'= %d, e o valor de 'b'= %.4f", a, b);
#endif

    if (kill(pid, 0) != 0)
        WARNING("kill do processo %d (nao termina o programa)", pid);

    if ((fd = open(file, O_CREAT | O_EXCL)) == -1)
        ERROR(1, "O ficheiro ja existe!!!", file);

    printf("esta linha nunca aparece, porque a funcao open da erro\n");

    return 0;
}
