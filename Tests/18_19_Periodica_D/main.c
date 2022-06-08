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

    int fd;
    int flags = O_RDONLY;

    if ((fd = open(args.file_arg, flags)) <= 0)
    {
        cmdline_parser_free(&args);
        ERROR(ERROR_FILE, "Could not open file for reading.");
    }

    if (args.verbose_given)
    {
        execute_verbose_mode(fd, &args);
    }
    else
    {
        execute_normal_mode(fd, &args);
    }

    close(fd);
    cmdline_parser_free(&args);

    return 0;
}
