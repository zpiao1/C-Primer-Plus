/* Exercise 6.5.c -- prints a letter pyramid */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char input;
    int size, row, col;
    printf("Enter a UPPERCASE character to start: ");
    scanf("%c", &input);
    size = input - 'A' + 1;
    for (row = 1; row <= size; row++)
    {
        for (col = 1; col <= 2 * size; col++)
            if (abs(col - size) < row)
                printf("%c", 'A' + row - abs(col - size) - 1);
            else
                printf(" ");
        printf("\n");
    }

    return 0;
}
