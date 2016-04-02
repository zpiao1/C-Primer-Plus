// Exercise 7.2.c -- shows all the chars with their corresponding ASCII code
#include <stdio.h>
int main(void)
{
    int count = 0;
    char ch;

    printf("Enter a text ending with # to show all the chars");
    printf(" and ASCII codes. \n");

    while ((ch = getchar()) != '#')
    {
        if (ch == '\n')
            continue;
        count++;
        printf("%c%4d\t", ch, ch);
        if (count % 8 == 0)
        {
            printf("\n");
        }
    }

    return 0;
}
