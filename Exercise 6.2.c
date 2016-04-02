/* Exercise 6.2.c -- prints '$' */
#include <stdio.h>
int main(void)
{
    const int SIZE = 5;
    int row, col;

    for (row = 1; row <= SIZE; row++)
    {
        for (col = 1; col <= row; col++)
            printf("$");
        printf("\n");
    }

    return 0;
}
