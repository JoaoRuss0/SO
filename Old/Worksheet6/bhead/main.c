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
#include <fcntl.h>

int main(int argc, char *argv[])
{
	/* Disable warnings */
	(void)argc; (void)argv;

	/* Main code */
	if(argc != 3)
	{
		ERROR(1, "Number of arguments given is not adequate");
	}
	
	int bytes_to_read = atoi(argv[1]);

	if(bytes_to_read <= 0)
	{
		ERROR(2, "Number of bytes to read has to be positive or could not be converted");
	}

	int fd = open(argv[2], O_RDONLY);

	if(fd == -1)
	{
		ERROR(3, "Could not open file");
	}
	
	printf("From %s read %d bytes\n", argv[2], bytes_to_read);

	char byte;
	ssize_t bytes_read, size = sizeof(byte);

	for(int i = 0; i < bytes_to_read; ++i)
	{
		bytes_read = read(fd, &byte, size);

		if(bytes_read == size)
		{
			printf("[#%03x] %02x\n", i + 1, byte);
			continue;
		}
		
		if(bytes_read == 0)
		{
			close(fd);
			ERROR(5, "No more bytes to read from %s", argv[2]);
		}

		if(bytes_read == -1)
		{
			close(fd);
			ERROR(6, "Error reading bytes from %s", argv[2]);
		}

		close(fd);
		ERROR(4, "Could not read %zu bytes from %s", size, argv[2]);
	}

	close(fd);

	return 0;
}
