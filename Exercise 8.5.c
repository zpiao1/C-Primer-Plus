// Exercise 8.5.c -- improved version of guess.c
#include <stdio.h>
int main(void)
{
    int guess = 50, max = 100, min = 0;
    char response;

    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess if right and with");
    printf("\nan h if it is too high, or an l if it is too low.\n");
    printf("Uh...is your number %d?\n", guess);
    while ((response = getchar()) != 'y')    /* get response, compare to y */
    {
        if (max - min == 1)
        {
            printf("Man, are you kidding?!\n");
            break;
        }
        if (response == 'h')
        {
            max = guess;
            guess = (int)((max + min) / 2);
            printf("Maybe it is %d, right?\n", guess);
        }
        else if (response == 'l')
        {
            min = guess;
            guess = (int)((max + min) / 2);
            printf("Maybe it is %d, right?\n", guess);
        }
        else
            printf("Sorry, I understand only y, h, or l.\n");
        while (getchar() != '\n')
            continue;                       /* skip rest of input line */
    }
    if (response == 'y')
        printf("I knew I could do it!\n");
    else
        printf("Don't cheat me next time...\n");

    return 0;
}
