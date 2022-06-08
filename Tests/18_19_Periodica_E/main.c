#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "debug.h"
#include "memory.h"
#include "aux.h"

#define ERROR_ARGS 1
#define ERROR_FILE 2

int main(int argc, char *argv[]){
    if(argc < 2) {
        fprintf(stdout, "Invalid number of arguments\nUsage: ./elf-parser <file>...\n");
        exit(ERROR_ARGS);
    }

    for(int i = 1; i < argc; i++) {

        struct stat path_stat;
        stat(argv[i], &path_stat);
        
        if(!S_ISREG(path_stat.st_mode)) {
            fprintf(stderr, "%s: Not a file\n", argv[i]);
            continue;
        }

        int fd;
        int flags = O_RDONLY;

        if((fd = open(argv[i], flags)) <= 0) {
            fprintf(stderr, "%s: %s\n", argv[i], strerror(errno));
            continue;
        }

        verify_if_elf(fd, argv[i]);

        close(fd);
    }

	return 0;
}

