#define _XOPEN_SOURCE
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc > 1) printf("%s\n", crypt(argv[1], argv[2]));
}