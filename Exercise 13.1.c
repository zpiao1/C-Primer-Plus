/* Exercise 13.1.c -- interactive version of Listing 13.1 count.c */
#include <stdio.h>
#include <stdlib.h> // exit() prototype
#include <string.h>
#define STRLEN 81

char * s_gets(char * st, int n);
int main(void)
{
    int ch;         // place to store each character as read
    FILE *fp;       // "file pointer"
    unsigned long count = 0;
    char filename[STRLEN];

    puts("Enter the filename:");
    s_gets(filename, STRLEN);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);   // same as putchar(ch);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", filename, count);

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
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
