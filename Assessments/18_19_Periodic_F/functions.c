#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#include "debug.h"
#include "functions.h"

#define ERROR_FILE 2

void invert_file(int fd, char *filename)
{
    char *inverted_filename = NULL;
    get_inverted_filename(&inverted_filename, filename);

    int flags = O_WRONLY | O_CREAT | O_EXCL;
    mode_t mode = S_IRWXU;
    int fd2 = open(inverted_filename, flags, mode);

    if(fd2 <= 0) {
        ERROR(2, "Could not open and create file for writing.");
    }

    unsigned char byte;
    off_t offset = lseek(fd, -1, SEEK_END);

    while(offset != 0) {
        if(read(fd, &byte, sizeof(unsigned char)) == -1) {
            ERROR(ERROR_FILE, "Error reading file '%s'", filename);
        }
        
        if(write(fd2, &byte, sizeof(unsigned char)) != 1) {
            ERROR(ERROR_FILE, "Error writing to file '%s'", filename);
        };

        offset = lseek(fd, -2, SEEK_CUR);
    }

    if(read(fd, &byte, sizeof(unsigned char)) == -1) {
        ERROR(ERROR_FILE, "Error reading file '%s'", filename);
    }

    if(write(fd2, &byte, sizeof(unsigned char)) != 1) {
        ERROR(ERROR_FILE, "Error writing to file '%s'", filename);
    };

    printf("Inverted file: %s (%zu bytes)\n", inverted_filename, lseek(fd2, 0, SEEK_END));

    free(inverted_filename);
}

void get_inverted_filename(char **inverted_filename, char *filename)
{
    *inverted_filename = (char *)calloc(strlen(filename) + strlen("_inverted") + 1, sizeof(char));
    char *token = strtok(filename, ".");

    strncat(*inverted_filename, token, strlen(token) + 1);
    strncat(*inverted_filename, "_inverted", strlen("_inverted") + 1);

    token = strtok(NULL, ".");

    while (token)
    {
        strncat(*inverted_filename, ".", strlen(".") + 1);
        strncat(*inverted_filename, token, strlen(token) + 1);

        token = strtok(NULL, ".");
    }
}