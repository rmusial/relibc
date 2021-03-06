#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* path = realpath("stdlib/realpath.c", NULL);
    if (!path) {
        perror("realpath");
        return -1;
    }
    puts(path);

    free(path);

    path = malloc(PATH_MAX);
    memset(path, 0, PATH_MAX);

    realpath("stdlib/realpath.c", path);
    if (!path) {
        perror("realpath");
        free(path);
        return -1;
    }
    puts(path);

    free(path);
}
