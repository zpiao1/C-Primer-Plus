// Exercise 7.6.c -- counts the number of times that "ei" occurs
#include <stdio.h>
int main(void)
{
    int count = 0;
    char pre_ch = '\n', cur_ch;

    printf("Enter some text, end with \"#\"\n");
    while ((cur_ch = getchar()) != '#')
    {
        if (pre_ch == 'e' && cur_ch == 'i')
            count++;
        pre_ch = cur_ch;
    }
    printf("\"ei\" occurs %d times\n", count);

    return 0;
}
