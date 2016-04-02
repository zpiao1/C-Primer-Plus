// Exercise 7.4.c -- symbol substitution
#include <stdio.h>
int main(void)
{
    int count = 0;
    char ch;

    printf("Enter a text to substitude, # to quit.\n");
    scanf("%c", &ch);
    while (ch != '#')
    {
        if (ch == '.')
            putchar('!');
        else if (ch = '!')
        {
            putchar('!');
            putchar('!');
        }
        else
            putchat(ch);
        scanf("%c", &ch);
    }

    return 0;
}
