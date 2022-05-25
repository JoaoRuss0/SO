#include <stdio.h>
#include <stdlib.h>
// #include <sys/wait.h>
#include <unistd.h>
// #include <signal.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// #include <assert.h>

#include "debug.h"

int main(int argc, char *argv[]) {
    /* Disable warnings */
    (void)argc;
    (void)argv;

    int flags = O_WRONLY;
    int fd = open("/dev/full", flags);

    if(fd <= 0) {
        ERROR(2, "%s\n", strerror(errno));
    }

    ssize_t count;

    for (int i = 0; i < 4; i++)
    {
        count = write(fd, &i, sizeof(i));

        if(count == 0 || count == -1) {
            ERROR(3, "%s\n", strerror(errno));
        }
    }

    close(fd);

    return 0;
}
