#include <stdlib.h>
#include <string.h>

void f1(void);
void f2(void);
void f3(void);
void f4(void);
void f5(void);

int main(void) {
    f5();
    f4();
    f3();
    f2();
    f1();

    return 0;
}

void f1(void) {
    int *ptr;
    ptr[0] = 1;
}

void f2(void) {
    int *ptr;
    free(ptr);
}

void f3(void) {
    int *ptr = malloc(sizeof(int));
    free(ptr);
    free(ptr);
}

void f4(void) {
    char ola[] = "ola mundo";
    char *str = malloc(strlen(ola));
    strcpy(str, ola);
}

void f5(void) {
    char *ola = "ola mundo";
    char *str = malloc(sizeof(ola) + 1);
    strcpy(str, ola);
}
