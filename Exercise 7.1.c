// Exercise 7.1.c -- counts different characters
#include <stdio.h>
int main(void)
{
    char ch;
    int n_spaces, n_newlines, n_otherchars;

    n_spaces = n_newlines = n_otherchars = 0;

    printf("Enter a text, end with #, to count the characters: \n");
    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
            n_spaces++;
        else if (ch == '\n')
            n_newlines++;
        else
            n_otherchars++;
    }
    printf("There are %d spaces, %d newlines, and %d ",
           n_spaces, n_newlines, n_otherchars);
    printf("other characters.\n");

    return 0;
}
