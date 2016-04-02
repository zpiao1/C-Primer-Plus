// Exercise 8.3.c -- counts the number of different letters
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int upp_cnt = 0, low_cnt = 0, oth_cnt = 0;
    char ch;

    printf("Enter a text to analyse:\n");
    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
            upp_cnt++;
        else if (islower(ch))
            low_cnt++;
        else
            oth_cnt++;
    }

    printf("Uppercase letters: %d\n", upp_cnt);
    printf("Lowercase letters: %d\n", low_cnt);
    printf("Other letters: %d\n", oth_cnt);

    return 0;
}
