#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#include "debug.h"
#include <time.h>

int main(int argc, char *argv[])
{
	if( argc != 2 )
	{
		ERROR(1,"Expecting 1 argument");				
	}
	
	int fd = open(argv[1], O_WRONLY | O_APPEND);

	if(fd == -1)
	{
		ERROR(2, "Could not open file");
	}
	
	// Holds current time since epoch
	time_t time_since_epoch;
	// Holds transformed time_t
	struct tm *tm;
	
	// Get current time
	time_since_epoch = time(NULL);
	// Transform it
	tm = localtime(&time_since_epoch);

	if(tm == NULL)
	{
		close(fd);
		ERROR(3, "Could not transform time_t");
	}

	char formated[16] = {'\0'};

	if(strftime(formated, sizeof(formated), "%Y.%m.%d", tm) == 0)
	{
		close(fd);
		ERROR(4, "Could not format struct tm");
	}
	
	formated[strlen(formated)] = '\n';

	ssize_t size = strlen(formated);
	ssize_t written_bytes = write(fd, formated, size);

	if(written_bytes != size)
	{
		close(fd);
		ERROR(5, "Could not write %zu bytes to %s", size, argv[1]);
	}
	
	close(fd);

	return 0;
}

