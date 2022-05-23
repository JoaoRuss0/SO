#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "debug.h"

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    /* insira o seu código aqui */

    if(argc != 2) {
        ERROR(1, "Invalid number of parameters, only the path to the file is needed.");
    }

	int flags = O_RDONLY;
    int fd = open(argv[1], flags);

    if(fd <= 0) {
        ERROR(2, "Could not open file for reading.");
    }

	char buf[BUFFER_SIZE];
	int count;

    do {
        count = read(fd, buf, BUFFER_SIZE - 1);

        if(count == -1) {
            close(fd);
            ERROR(3, "Error reading file.");
        }

		buf[count] = '\0';
        fprintf(stdout, "%s", buf);

    } while (count != 0);
    
	fprintf(stdout, "\n");

    close(fd);

    return 0;
}
