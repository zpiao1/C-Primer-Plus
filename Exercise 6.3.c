/* Exercise 6.3.c -- prints LETTERS */
#include <stdio.h>
int main(void)
{
    const int SIZE = 'F' - 'A' + 1;
    int row, col;

    for (row = 1; row <= SIZE; row++)
    {
        for (col = 1; col <= row; col++)
            printf("%c", 'F' - col + 1);
        printf("\n");
    }

    return 0;
}

