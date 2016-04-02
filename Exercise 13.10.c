/* Exercise 13.10.c -- Go to the position provided and prints
   until the newline */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 81
char *s_gets(char *st, int n);
int main(void)
{
    char filename[LEN];
    FILE *fp;
    int pos;
    char ch;

    puts("Enter the filename:");
    s_gets(filename, LEN);
    fp = fopen(filename, "r");
    if (!fp)
    {
        fprintf(stderr, "Cannot open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    puts("Enter the file position:");
    while ((scanf("%d", &pos) == 1) && (pos >= 0))
    {
        fseek(fp, pos, SEEK_SET);
        while ((ch = getc(fp)) != '\n')
            putchar(ch);
        putchar('\n');
        puts("Enter the next file position, end with negative or nonnumeric value:");
    }
    puts("Done.");
    fclose(fp);
    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val, *find;

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
