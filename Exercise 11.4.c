/* Exercise 11.4.c -- reads a word and discards
   the rest of line */
#include <stdio.h>
#include <ctype.h>
#define SIZE 50
void getword(char * pt, int n);
int main(void)
{
    char str[SIZE];

    puts("Enter a line:");
    getword(str, SIZE);
    puts(str);

    return 0;
}

void getword(char * pt, int n)
{
    char ch;
    int i = 0;
    ch = getchar();
    while (isblank(ch))
        continue;
    while (!isblank(ch))
    {
        if (i == n - 1)
            break;
        *(pt + i) = ch;
        i++;
        ch = getchar();
    }
    *(pt + i) = '\0';
    while (getchar() != '\n')
        continue;
}

