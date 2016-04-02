/* Exercise 11.5.c -- strchr() function */
#include <stdio.h>
char * findch(char * str, const char ch);
int main(void)
{
    char str[50];
    char ch;
    char * ptr;
    puts("Enter a word:");
    fgets(str, 50, stdin);
    for (ch = 'a'; ch <= 'z'; ch++)
    {
        ptr = findch(str, ch);
        if (ptr)
            printf("%c %s", *ptr, ptr);
    }

    return 0;
}

char * findch(char * str, const char ch)
{
    char * pt;
    for (pt = str; *pt != '\0'; pt++)
    {
        if (*pt == ch)
            return (pt);
    }
    return NULL;
}
