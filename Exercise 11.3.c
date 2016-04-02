/* Exercise 11.3.c -- reads a word and discards
   the rest of line */
#include <stdio.h>
#include <ctype.h>
#define SIZE 50
void getword(char * pt);
int main(void)
{
    char str[SIZE];

    puts("Enter a line:");
    getword(str);
    puts(str);

    return 0;
}

void getword(char * pt)
{
    char ch;
    int i = 0;
    ch = getchar();
    while (isblank(ch))
        continue;
    while (!isblank(ch))
    {
        *(pt + i) = ch;
        i++;
        ch = getchar();
    }
    *(pt + i) = '\0';
    while (getchar() != '\n')
        continue;
}
