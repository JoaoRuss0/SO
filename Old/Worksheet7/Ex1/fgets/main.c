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
	char buffer[255];

	while(fgets(buffer, sizeof(buffer), ptr) != NULL)
	{
		fprintf(stdout, "%03d: %s", i, buffer);
		++i;
	}

	fclose(ptr);
	return 0;
}

