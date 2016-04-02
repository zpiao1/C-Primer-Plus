// Exercise 7.5.c -- Substitution of chars using switch
#include <stdio.h>
int main(void)
{
    char ch;

    printf("Enter some text, end with \"#\"\n");
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
            case '.': printf("!"); break;
            case '!': printf("!!"); break;
            default: printf("%c", ch);
        }
    }

    return 0;
}
