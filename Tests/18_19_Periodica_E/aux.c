#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "aux.h"

int file_types = 5;

file_type file_types_array[5] = {
    { 0x00, "No file type"},
    { 0x01, "Object file"},
    { 0x02, "Executable"},
    { 0x03, "Shared object file"},
    { 0x04, "Core file"}
};

void verify_if_elf(int fd, char *filename) {
    uint32_t first_four;
    uint8_t fifth, type;

    printf("%s: ", filename);

    if(read(fd, &first_four, 4) != 4){
        fprintf(stderr, "Error reading file\n");
        return;
    }

    if(first_four != 0x464c457f) {
        fprintf(stderr, "NOT ELF\n");
        return;
    }

    if(read(fd, &fifth, 1) != 1){
        fprintf(stderr, "Error reading file\n");
        return;
    }

    if(fifth == 1) {
        printf("32 bits; ");
    }else if(fifth == 2){
        printf("64 bits; ");
    }

    if(lseek(fd, 16, SEEK_SET) != 16) {
        fprintf(stderr, "Error reading file\n");
        return;
    };

    if(read(fd, &type, 1) != 1){
        fprintf(stderr, "Error reading file\n");
        return;
    }

    for(int i = 0; i < file_types; i++) {
        if(file_types_array[i].value == type) {
            printf("%s\n", file_types_array[i].name);
            break;
        }
    }
}