#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "debug.h"


int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Error not enough parameters!");
		exit(1);
	}
	
	mode_t mode = 0644;
	int fd = open(argv[1], O_WRONLY | O_CREAT, mode);
	
	if(fd == -1)
	{
		fprintf(stderr, "Could not open file %s\nErrno (%d): %s\n", argv[1], errno, strerror(errno));
		exit(2);
	}
	
	int array_to_write[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ssize_t written_bytes, size = sizeof(array_to_write);

	written_bytes = write(fd, array_to_write, size);
	
	if(written_bytes != size)
	{
		close(fd);
		fprintf(stderr, "Could not write %zu bytes to %s\nErrno (%d): %s\n", size, argv[1], errno, strerror(errno));
		exit(3);
	}	

	close(fd);
	return 0;
}
