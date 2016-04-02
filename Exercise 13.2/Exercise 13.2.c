/* Exercise 13.2.c -- copies a file to the other */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *src, *cpy;
    char ch;

    if (argc != 3)
    {
        printf("Usage: %s copyfrom copyto\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (strcmp(argv[1], argv[2]) == 0)
    {
        printf("Can't copy a file to itself\n");
        exit(EXIT_FAILURE);
    }
    src = fopen(argv[1], "rb");
    cpy = fopen(argv[2], "wb");
    if (!src)
    {
        printf("Can't open the source file!\n");
        exit(EXIT_FAILURE);
    }
    if (!cpy)
    {
        printf("Can't open the copy file!\n");
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(src)) != EOF)
        putc(ch, cpy);

    fclose(src);
    fclose(cpy);

    return 0;
}
