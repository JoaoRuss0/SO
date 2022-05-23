#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "debug.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "write_file: wrong number of parameters.\n");
        fprintf(stderr, "usage: write_file <file>\n");
        exit(1);
    }

    int flags = O_WRONLY | O_CREAT;
    mode_t mode = S_IRWXU;
    int fd = open(argv[1], flags, mode);

    if(fd <= 0) {
        ERROR(2, "Could not open file for reading.");
    }

	char buf[3];
	int count;
    
    for (int i = 1; i <= 10; i++)
    {
        write(fd, &i, sizeof(i));
    }
    
    for (int i = 1; i <= 10; i++)
    {
        count = snprintf(buf, 3, "%d", i);

        if(count < 0) {
            ERROR(2, "Could not write to file.");
        }

        buf[count] = '\0';

        write(fd, buf, count + 1);
    }

    close(fd);

    return 0;
}