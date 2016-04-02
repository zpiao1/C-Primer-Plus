/* Exercise 11.2.c -- get input until n chars
   or whitespaces */
#include <stdio.h>
#include <ctype.h>
#define SIZE 50
void getstr(char * str, int n);
int main(void)
{
    char str[SIZE];
    puts("Enter the string:");
    getstr(str, SIZE);
    puts(str);

    return 0;
}
void getstr(char * str, int n)
{
    int i;
    char ch;
    for (i = 0; i < n - 1; i++)
    {
        ch = getchar();
        if (ch == ' ' || ch == '\t' || ch == '\n')
            break;
        else
            *(str + i) = ch;
    }
    *(str + i) = '\0';
}
