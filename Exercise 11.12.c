/* Exercise 11.12.c -- statistics on text */
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char curr, prev = '\n';
    int wd_ct = 0, upp_ct = 0, low_ct = 0;
    int pun_ct = 0, dig_ct = 0;
    puts("Enter a text to analyse:");
    while ((curr = getchar()) != EOF)
    {
        if (isupper(curr))
            upp_ct++;
        else if (islower(curr))
            low_ct++;
        else if (isdigit(curr))
            dig_ct++;
        else
            pun_ct++;
        if ((prev == ' ' || prev == '\n') && isalnum(curr))
            wd_ct++;
    }
    printf("words   uppercase   lowercase\n");
    printf("%d      %d          %d\n", wd_ct, upp_ct, low_ct);
    printf("punctuations    digits\n");
    printf("%d              %d", pun_ct, dig_ct);

    return 0;
}
