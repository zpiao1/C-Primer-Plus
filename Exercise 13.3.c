/* Exercise 13.3.c -- copies and converts the file to uppercase */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define STRLEN 81
char * s_gets(char * st, int n);
void copyfile(FILE * source, FILE * output);
int main(void)
{
    char srcname[STRLEN];
    char outname[STRLEN];
    FILE *src, *out;

    puts("Enter the source filename:");
    s_gets(srcname, STRLEN);
    puts("Enter the output filename:");
    s_gets(outname, STRLEN);

    src = fopen(srcname, "r");
    out = fopen(outname, "w");

    if (!src || !out)
    {
        printf("Error in opening files.\n");
        exit(EXIT_FAILURE);
    }

    copyfile(src, out);

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, STRLEN, stdin);
    if (ret_val)
    {
        if (find = strchr(st, '\n'))
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}

void copyfile (FILE * source, FILE * output)
{
    char ch;
    while ((ch = getc(source)) != EOF)
        putc(toupper(ch), output);
}
