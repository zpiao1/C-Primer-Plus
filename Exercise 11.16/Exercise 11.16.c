/* Exercise 11.16.c -- echoes the input as indicated */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char ch;

    puts("Enter your input");
    if (argc == 1 || (argc == 2 && strcmp(argv[1], "-p") == 0))
    {
        while ((ch = getchar()) != EOF)
            putchar(ch);
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "-u") == 0)
            while ((ch = getchar()) != EOF)
            {
                if (islower(ch))
                    putchar(ch - 'a' + 'A');
                else
                    putchar(ch);
            }
        else if (strcmp(argv[1], "-l") == 0)
            while ((ch = getchar()) != EOF)
            {
                if (isupper(ch))
                    putchar(ch - 'A' + 'a');
                else
                    putchar(ch);
            }
    }
    else
        puts("Error");

    return 0;
}
