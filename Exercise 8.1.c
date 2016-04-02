// Exercise 8.1.c -- counts the number of characters up to EOF
#include <stdio.h>
int main(void)
{
    char ch;
    int i = 0;

    printf("Enter some characters to count:\n");
    while ((ch = getchar()) != EOF)
        i++;
    printf("There are %d characters in total.\n", i);

    return 0;
}
