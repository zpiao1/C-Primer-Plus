/* Exercise 13.8.c -- counts the times that a char occurs */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char ch, chgot;
    int count = 0;
    int i;
    FILE *fp;

    if (argc < 2)
    {
        printf("Usage: %s aChar [file1 file2...]", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (strlen(argv[1]) != 1)
    {
        printf("The first argument should be a single char:\n");
        exit(EXIT_FAILURE);
    }
    ch = argv[1][0];
    if (argc == 2)
    {
        puts("Enter a text, end with EOF");
        while ((chgot = getchar()) != EOF)
            if (ch == chgot)
                count++;
        printf("Number of %c: %d\n", ch, count);
    }
    else
    {
        for (i = 2; i < argc; i++)
        {
            fp = fopen(argv[i], "r");
            if (!fp)
            {
                printf("Can't open %s\n", argv[i]);
                continue;
            }
            while ((chgot = getc(fp)) != EOF)
                if (ch == chgot)
                    count++;
            printf("Number of %c in %s: %d\n", ch, argv[i],
                   count);
            fclose(fp);
            count = 0;
        }
    }
}
