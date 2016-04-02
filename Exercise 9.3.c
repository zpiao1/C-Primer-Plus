/* Exercise 9.3.c -- print character rectangle */
#include <stdio.h>
#include <ctype.h>
void ch_rect(char ch, int row, int col);
int main(void)
{
    char ch;
    int row, col;

    printf("Enter the character to be printed: \n");
    while (!isprint(ch = getchar()))
    {
        printf("Please enter a printable character.\n");
    }
    printf("Enter the number of row and columns: \n");
    while (scanf("%d%d", &row, &col) != 2)
    {
        printf("Please enter two integers.\n");
    }
    ch_rect(ch, row, col);

    return 0;
}

void ch_rect(char ch, int row, int col)
{
    int x, y;
    for (y = 1; y <= row; y++)
    {
        for (x = 1; x <= col; x++)
            putchar(ch);
        putchar('\n');
    }
}
