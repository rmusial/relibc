#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
    puts("# mem #");
    char arr[100];
    memset(arr, 0, 100); // Compiler builtin, should work
    arr[50] = 1;
    if ((size_t)memchr((void *)arr, 1, 100) - (size_t)arr != 50) {
        puts("Incorrect memchr");
        exit(1);
    }
    puts("Correct memchr");
    char arr2[51];
    memset(arr2, 0, 51); // Compiler builtin, should work
    memccpy((void *)arr2, (void *)arr, 1, 100);
    if (arr[50] != 1) {
        puts("Incorrect memccpy");
        exit(1);
    }
    puts("Correct memccpy");
    int res;
    if ((res = memcmp("hello world", "hello world", 11))) {
        printf("Incorrect memcmp (1), expected 0 found %d\n", res);
        exit(1);
    }
    if ((res = memcmp("hello world", "hello worlt", 11)) >= 0) {
        printf("Incorrect memcmp (2), expected -, found %d\n", res);
        exit(1);
    }
    if ((res = memcmp("hello world", "hallo world", 5)) <= 0) {
        printf("Incorrect memcmp (3), expected +, found %d\n", res);
        exit(1);
    }
    if ((res = memcmp("hello world", "henlo world", 5)) >= 0) {
        printf("Incorrect memcmp (4), expected -, found %d\n", res);
        exit(1);
    }
    puts("Correct memcmp");
    return 0;
}
