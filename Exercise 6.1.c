/* Exercise 6.1.c -- uses array to store lowercase letters */
#include <stdio.h>
int main(void)
{
    const int SIZE = 26;
    char letters[SIZE];
    int i;

    for (i = 0; i < SIZE; i++)
        letters[i] = 'a' + i;
    for (i = 0; i < SIZE; i++)
        printf("letters[%d] = %c\n", i, letters[i]);

    return 0;
}
