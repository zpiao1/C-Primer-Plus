/* Exercise 11.9.c -- reverse a function */
#include <stdio.h>
#define SIZE 50
void reverse_str(char * str);
char * s_gets(char * st, int n);
int main(void)
{
    char string[SIZE];
    puts("Enter a string:");
    s_gets(string, SIZE);
    while (string[0] != '\0')
    {
        reverse_str(string);
        puts(string);
        s_gets(string, SIZE);
    }

    return 0;
}

void reverse_str(char * str)
{
    int i = 0, j;
    char temp;
    while (str[i] != '\0')
        i++;
    j = i - 1;
    for (i = 0; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

char * s_gets(char *st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

