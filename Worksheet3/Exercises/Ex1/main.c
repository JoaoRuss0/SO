#include <stdio.h>
#include <string.h>

int main (int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Insufficient number of parameters. One string is required.\n");
        return 1;
    }

    char *opposites1[3] = {"big", "tall", "high" };
    char *opposites2[3] = {"small", "short", "low" };

    for (int i = 0; i < 3; ++i) {
        if (strcmp(argv[1], opposites1[i]) == 0) {
            printf("%s\n", opposites2[i]);
            return 0;
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (strcmp(argv[1], opposites2[i]) == 0) {
            printf("%s\n", opposites1[i]);
            return 0;
        }
    }

    printf("Opposite not found!\n");

    return 0;
}