/* Exercise 13.4.c -- displays the file contents sequentially */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE * src;
    int i;
    char ch;

    if (argc < 2)
    {
        printf("Usage: %s file1 file2...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (i = 1; i < argc; i++)
    {
        src = fopen(argv[i], "r");
        if (src)
        {
            printf("Displaying %s:\n", argv[i]);
            while ((ch = getc(src)) != EOF)
                putchar(ch);
        }
        else
            printf("Can't open file %s\n", argv[i]);
    }

    return 0;
}
