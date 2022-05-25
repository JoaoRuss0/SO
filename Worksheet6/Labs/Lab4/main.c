#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#include "debug.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        ERROR(1, "expecting 1 argument, got %d\nSysntax: %s filename", argc - 1, argv[0]);
    }

    int flags = O_WRONLY | O_CREAT | O_APPEND;
    mode_t mode = S_IRWXU;
    int fd = open(argv[1], flags, mode);

    if(fd <= 0) {
        ERROR(2, "Could not open file for reading.");
    }

	char date[11];
    time_t now;

    time(&now);
    struct tm *now_tm = localtime(&now);
    strftime(date, sizeof(date), "%Y.%m.%d", now_tm);

    write(fd, date, sizeof(date));
    
    close(fd);

    return 0;
}
