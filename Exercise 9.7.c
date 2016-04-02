/* Exercise 9.7.c -- analyse the characters */
#include <stdio.h>
#include <ctype.h>
int location(char ch);
int main(void)
{
    char ch;
    while ((ch = getchar()) != EOF)
    {
        printf("Location: %d\n", location(ch));
    }

    return 0;
}

int location(char ch)
{
    if (islower(ch))
        return (ch - 'a' + 1);
    else if (isupper(ch))
        return (ch - 'A' + 1);
    else
        return -1;
}
