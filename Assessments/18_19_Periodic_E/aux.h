#ifndef __AUX_H__
#define __AUX_H__

typedef struct {
    unsigned char value;
    char *name;
} file_type;

void verify_if_elf(int fd, char *filename);

#endif