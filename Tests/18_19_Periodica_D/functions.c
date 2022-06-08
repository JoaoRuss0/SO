#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "args.h"
#include "functions.h"
#include "debug.h"

#define ERROR_FILE 2

void execute_verbose_mode(int fd, struct gengetopt_args_info *args)
{

    printf("[Verbose mode]\n");

    int is_ascii = 1, count, position = 1, quantity_not_ascii = 0;
    unsigned char byte;

    while ((count = read(fd, &byte, sizeof(unsigned char))) == 1)
    {
        if (byte > 127)
        {
            printf("Byte %d:%d (>127)\n", position, byte);
            quantity_not_ascii++;
            is_ascii = 0;
        }

        position++;
    }

    if (count == -1)
    {
        close(fd);
        cmdline_parser_free(args);
        ERROR(ERROR_FILE, "Error reading file");
    }

    printf("Summary: %d bytes not ASCII\n", quantity_not_ascii);

    if (is_ascii == 1)
    {
        printf("'%s' is ASCII\n", args->file_arg);
    }
    else
    {
        printf("'%s' is NOT ASCII\n", args->file_arg);
    }
}

void execute_normal_mode(int fd, struct gengetopt_args_info *args)
{

    int is_ascii = 1, count, position = 0;
    unsigned char byte;

    while ((count = read(fd, &byte, sizeof(unsigned char))) == 1)
    {
        if (byte > 127)
        {
            printf("'%s' is NOT ASCII\n", args->file_arg);
            is_ascii = 0;
            break;
        }
        position++;
    }

    if (count == -1)
    {
        close(fd);
        cmdline_parser_free(args);
        ERROR(ERROR_FILE, "Error reading file");
    }

    if (is_ascii == 0)
    {
        return;
    }

    printf("'%s' is ASCII\n", args->file_arg);
}