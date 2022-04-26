/**
* @file main.c
* @brief Description
* @date 2018-1-1
* @author name of author
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "debug.h"
#include "memory.h"

int main(int argc, char *argv[]){
	/* Disable warnings */
	(void)argc; (void)argv;

	/* Main code */
	char *file = "/etc/passwd";
	FILE *ptr = fopen(file, "r");

	if(ptr == NULL)
	{
		ERROR(1, "Could not open file %s to read contentes", file);
	}
	
	int i = 1;
	char *line_ptr = NULL;
	ssize_t res;
	size_t n = 0;

	while((res = getline(&line_ptr, &n , ptr)) != -1)
	{
		fprintf(stdout, "%03d (%zu bytes): %s", i, res, line_ptr);
		++i;
	}
	
	free(line_ptr);
	fclose(ptr);
	return 0;
}

