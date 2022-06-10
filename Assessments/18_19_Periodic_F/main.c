#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "debug.h"
#include "args.h"
#include "functions.h"

#define ERROR_ARGS 1
#define ERROR_FILE 2

int main(int argc, char *argv[])
{
    struct gengetopt_args_info args;

    if (cmdline_parser(argc, argv, &args) != 0)
    {
        ERROR(ERROR_ARGS, "Could not parse command line arguments.");
    }

    char *filename = (char *)malloc(strlen(args.file_arg) + 1);
    strncpy(filename, args.file_arg, strlen(args.file_arg) + 1);

    int fd, flags = O_RDONLY;

    if ((fd = open(filename, flags)) <= 0)
    {
        cmdline_parser_free(&args);
        fprintf(stdout, "ERROR: Could not open file '%s': %s\n", filename, strerror(errno));
        free(filename);
        exit(ERROR_FILE);
    }

    off_t file_size;

    if ((file_size = lseek(fd, 0, SEEK_END)) == -1)
    {
        cmdline_parser_free(&args);
        free(filename);
        ERROR(ERROR_FILE, "Could not get file size");
    };

    if (lseek(fd, 0, SEEK_SET) == -1)
    {
        cmdline_parser_free(&args);
        free(filename);
        ERROR(ERROR_FILE, "Could not reposition file's descriptor");
    };

    printf("File to invert: %s (%zu bytes)\n", filename, file_size);

    invert_file(fd, filename);

    if (close(fd) != 0)
    {
        cmdline_parser_free(&args);
        free(filename);
        ERROR(ERROR_FILE, "Could not close file descriptor");
    }

    cmdline_parser_free(&args);

    return 0;
}