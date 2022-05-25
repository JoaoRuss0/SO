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

typedef struct {
    int id;
    char *name;
} os;

int main(int argc, char *argv[]){
	/* Disable warnings */
	(void)argc; (void)argv;

	struct gengetopt_args_info args;

    if(cmdline_parser(argc, argv, &args) != 0 ) {
        ERROR(1, "Could not parse command line arguments.");
    }

    os os_list[] = {
        {0, "FAT filesystem (MS-DOS, OS/2, NT/Win32)"},
        {1, "Amiga"},
        {2, "VMS (or OpenVMS)"},
        {3, "Unix"},
        {4, "VM/CMS"},
        {5, "Atari TOS"},
        {6, "HPFS filesystem (OS/2, NT)"},
        {7, "Macintosh"},
        {8, "Z-System"},
        {9, "CP/M"},
        {10, "TOPS-20"},
        {11, "NTFS filesystem (NT)"},
        {12, "QDOS"},
        {13, "Acorn RISCOS"},
        {255, "unknown"}
    };

    char *filename = (char *) malloc(strlen(args.filename_arg) + 1);
    strncpy(filename, args.filename_arg, strlen(args.filename_arg) + 1);

    int flags = O_RDONLY;
    int fd = open(filename, flags);

    if(fd == -1) {
        cmdline_parser_free(&args);
        ERROR(2, "");
    }

    unsigned char ID1, ID2, OS;
    u_int32_t MTIME;
    ssize_t read_bytes;

    // Positions the file descriptor at the start of the file
    off_t offset = lseek(fd, 0, SEEK_SET);

    read_bytes = read(fd, &ID1, sizeof(ID1));

    if(read_bytes == -1) {
        free(filename);
        cmdline_parser_free(&args);
        ERROR(3, "Could not read file.");
    }

    if(read_bytes == 0) {
        free(filename);
        cmdline_parser_free(&args);
        ERROR(5, "No more to read.");
    }

    printf("ID1=0x%02x\n", ID1);

    read_bytes = read(fd, &ID2, sizeof(ID2));

    if(read_bytes == -1) {
        free(filename);
        cmdline_parser_free(&args);
        ERROR(3, "Could not read file.");
    }

    if(read_bytes == 0) {
        free(filename);
        cmdline_parser_free(&args);
        ERROR(5, "No more to read.");
    }

    printf("ID2=0x%02x\n", ID2);

    // Positions the file descriptor at the start of 5th octet
    offset = lseek(fd, 2, SEEK_CUR);

    if(offset != 4) {
        free(filename);
        cmdline_parser_free(&args);
        ERROR(4, "File descriptor is not positioned at the start of the 5th octet.");
    }

    read_bytes = read(fd, &MTIME, sizeof(MTIME));

    if(read_bytes == -1) {
        free(filename);
        cmdline_parser_free(&args);
        ERROR(3, "Could not read file.");
    }

    if(read_bytes == 0) {
        free(filename);
        cmdline_parser_free(&args);
        ERROR(5, "No more to read.");
    }

    printf("MTIME=%d\n", MTIME);

    // Positions the file descriptor at the start of 10th octet
    offset = lseek(fd, 1, SEEK_CUR);

    if(offset != 9) {
        free(filename);
        cmdline_parser_free(&args);
        ERROR(4, "File descriptor is not positioned at the start of the 10th octet.");
    }

    read_bytes = read(fd, &OS, sizeof(OS));

    if(read_bytes == -1) {
        free(filename);
        cmdline_parser_free(&args);
        ERROR(3, "Could not read file.");
    }

    if(read_bytes == 0) {
        free(filename);
        cmdline_parser_free(&args);
        ERROR(5, "No more to read.");
    }


    for (size_t i = 0; i < sizeof(os_list)/sizeof(os); i++) {
        if(os_list[i].id == (int) OS) {
            printf("OS=%d (%s)\n", OS, os_list[i].name);
            break;
        }
    }

    free(filename);
    cmdline_parser_free(&args);

	return 0;
}
