/* Exercise 11.8.c -- string_in() function */
#include <stdio.h>
#define SIZE 50
char * string_in(char *s1, char *s2);
char * s_gets(char * st, int n);
int main(void)
{
    char s1[SIZE], s2[SIZE];
    char * ptr;

    puts("Enter s1:");
    s_gets(s1, SIZE);
    puts("Enter s2:");
    s_gets(s2, SIZE);
    while (s1[0] != '\0' && s2[0] != '\0')
    {
        ptr = string_in(s1, s2);
        if (ptr)
            printf("%p %c %s\n", ptr, *ptr, ptr);
        else
            puts("Cannot find s2 in s1!");
        puts("Enter s1:");
        s_gets(s1, SIZE);
        puts("Enter s2:");
        s_gets(s2, SIZE);
    }

}

char * string_in(char *s1, char *s2)
{
    char *p1 = s1;
    char *p2 = s2;
    char * ret_val;
    while (*p1 != '\0' && *p1 != *p2)
        p1++;
    if (*p1 == '\0')
        return NULL;
    ret_val = p1;
    while (*p2 != '\0')
    {
        if (*p1 != *p2)
            return NULL;
        p1++;
        p2++;
    }
    return ret_val;
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
