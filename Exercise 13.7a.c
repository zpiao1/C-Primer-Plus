/* Exercise 13.7a.c -- prints lines in two files alternatively */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 81
void printlns(FILE *f1, FILE *f2);
char *s_gets(char *st, int n);
int main(void)
{
    char file1[LEN];
    char file2[LEN];
    FILE *fp1, *fp2;
    int count;

    puts("Enter the name of file1");
    s_gets(file1, LEN);
    puts("Enter the name of file2");
    s_gets(file2, LEN);

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");
    if (!fp1)
    {
        fprintf(stderr, "Can't open %s\n", file1);
        exit(EXIT_FAILURE);
    }
    if (!fp2)
    {
        fprintf(stderr, "Can't open %s\n", file2);
        exit(EXIT_FAILURE);
    }

    printlns(fp1, fp2);
    fclose(fp1);
    fclose(fp2);
    return 0;
}

void printlns(FILE *f1, FILE *f2)
{
    char c1, c2;
    while ((!feof(f1)) && (!feof(f2)))
    {
        c1 = getc(f1);
        while (c1 != EOF && c1 != '\n')
        {
            putchar(c1);
            c1 = getc(f1);
        }
        if (c1 == '\n')
            putchar(c1);
        c2 = getc(f2);
        while (c2 != EOF && c2 != '\n')
        {
            putchar(c2);
            c2 = getc(f2);
        }
        if (c2 == '\n')
            putchar(c2);
    }
    if (feof(f1))
        while ((c2 = getc(f2)) != EOF)
            putchar(c2);
    else if (feof(f2))
        while ((c1 = getc(f1)) != EOF)
            putchar(c1);
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
