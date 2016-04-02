/* Exercise 11.15.c -- implement atoi() function */
#include <stdio.h>
#include <ctype.h>
int myatoi(const char * string);
char * s_gets(char * st, int n);
int main(void)
{
    char str[50];
    int cvt;

    puts("Enter a number to convert:");
    s_gets(str, 50);
    while (str[0] != '\0')
    {
        cvt = myatoi(str);
        printf("The converted number is"
               " %d\n", cvt);
        puts("Enter the next number:");
        s_gets(str, 50);
    }

    return 0;
}

int myatoi(const char * string)
{
    int i = 0;
    int ret = 0;
    while (string[i] != '\0')
    {
        if (!isdigit(string[i]))
            return 0;
        ret = ret * 10 + (string[i] - '0');
        i++;
    }
    return ret;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\0' && st[i] != '\n')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
}
