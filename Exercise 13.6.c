/* Exercise 13.6.c -- interactive version of Listing 13.2
   reducto.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 81
char * s_gets(char * st, int n);
int main(void)
{
    FILE *in, *out;     // declare two FILE pointers
    int ch;
    char name[LEN];     // storage for output filename
    char inname[LEN - 5];
    int count = 0;

    // get input filename
    puts("Enter the input filename:");
    s_gets(inname, LEN - 5);
    // set up input
    if ((in = fopen(inname, "r")) == NULL)
    {
        fprintf(stderr, "I could't open the file \"%s\"\n",
                inname);
        exit(EXIT_FAILURE);
    }
    // process to get the output filename
    strncpy(name, inname, LEN - 5); // copy filename
    name[LEN - 5] = '\0';
    strcat(name, ".red");           // append .red
    // set up output
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    // copy data
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);  // print every 3rd char
    // clean up
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
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
