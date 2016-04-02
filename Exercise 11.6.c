/* Exercise 11.6.c -- is_within() function */
#include <stdio.h>
int is_within(const char ch, char * str);
int main(void)
{
    char ch;
    char string[50];
    puts("Enter a string:");
    fgets(string, 50, stdin);
    for (ch = 'a'; ch <= 'z'; ch++)
    {
        printf("\"%c\" is %sin \"%s\"", ch, (is_within(ch, string) ? "" :
               "not "), string);
    }

    return 0;
}

int is_within(const char ch, char * str)
{
    char * pt;
    for (pt = str; *pt != '\0'; pt++)
    {
        if (*pt == ch)
            return 1;
    }
    return 0;
}
