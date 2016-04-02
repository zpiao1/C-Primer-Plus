/* Exercise 6.4.c -- prints LETTERS */
#include <stdio.h>
int main(void)
{
    const int SIZE = 6;
    int row, col, count;

    for (row = 1, count = 1; row <= SIZE; row++)
    {
        for (col = 1; col <= row; col++, count++)
            printf("%c", 'A' + count - 1);
        printf("\n");
    }

    return 0;
}

