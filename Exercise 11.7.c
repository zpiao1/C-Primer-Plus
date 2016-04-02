/* Exercise 11.7.c -- mystrncpy() function */
#include <stdio.h>
#define SIZE 50
char * mystrncpy(char *s1, const char *s2, int n);
char * s_gets(char * st, int n);
int main(void)
{
    char str1[SIZE], str2[SIZE];

    puts("Enter a line, empty line to quit: ");
    s_gets(str2, SIZE);
    while (str2[0] != '\0')
    {
        mystrncpy(str1, str2, SIZE);
        printf("%s", str1);
        s_gets(str2, SIZE);
    }
    return 0;
}

char * mystrncpy(char *s1, const char *s2, int n)
{
    char *p1 = s1;
    const char *p2 = s2;
    int i = 0;
    while (i < n && *p2 != '\0')
    {
        *p1 = *p2;
        p1++;
        p2++;
        i++;
    }
    *(p1 + i) = '\0';
    return s1;
}

char * s_gets(char * st, int n)
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
