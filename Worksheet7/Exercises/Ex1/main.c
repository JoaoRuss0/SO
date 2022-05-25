#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "debug.h"
#include "memory.h"

#define ERROR_FILE          1
#define MAX_STRING_LENGTH   1024

void read_file_fgets();
void read_file_getline(FILE *file_ptr);

int main(int argc, char *argv[]){
	/* Disable warnings */
	(void)argc; (void)argv;

    FILE *file_ptr = fopen("/etc/passwd", "r");

    if(file_ptr == NULL) {
        ERROR(ERROR_FILE, "Could not open file for reading.");
    }

    //read_file_fgets(file_ptr);
    read_file_getline(file_ptr);

    fclose(file_ptr);

	return 0;
}

void read_file_fgets(FILE *file_ptr) {

    char string[MAX_STRING_LENGTH];

    while((fgets(string, MAX_STRING_LENGTH, file_ptr) != NULL)) {
        printf("%s", string);
    }

    if(!feof(file_ptr)) {
        ERROR(ERROR_FILE, "Reading error.");
    }
}

void read_file_getline(FILE *file_ptr) {

    char *string;
    size_t n = 0;
    ssize_t read_bytes;

    while((read_bytes = getline(&string, &n, file_ptr) != -1)) {
        printf("%s", string);
    }

    free(string);

    if(!feof(file_ptr)) {
        ERROR(ERROR_FILE, "Reading error.");
    }
}