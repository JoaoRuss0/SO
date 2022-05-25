#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "debug.h"
#include "memory.h"
#include "args.h"

int main(int argc, char *argv[]){
	/* Disable warnings */
	(void)argc; (void)argv;

	struct gengetopt_args_info args;

    if(cmdline_parser(argc, argv, &args) != 0 ) {
        ERROR(1, "Could not parse command line arguments.");
    }

    int num_bytes = args.num_bytes_arg;
    char *filename = (char *) malloc(strlen(args.filename_arg) + 1);

    strncpy(filename, args.filename_arg, strlen(args.filename_arg) + 1);

    int flags = O_RDONLY;
    int fd = open(filename, flags);

    if(fd == -1) {
        ERROR(2, "");
    }

    char buf;
    ssize_t bytes_read;

    for (int i = 0; i < num_bytes; i++)
    {
        bytes_read = read(fd, &buf, 1);

        if(bytes_read == 0) {
            printf("[#%03d] No more to read.\n", i + 1);
            break;
        }

        if(bytes_read == -1) {
            free(filename);
            cmdline_parser_free(&args);

            ERROR(3, "");
        }

        printf("[#%03d] %02x\n", i + 1, buf);
    }

    free(filename);
    cmdline_parser_free(&args);

	return 0;
}