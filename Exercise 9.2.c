/* Exercise 9.2.c -- chline(ch, i, j) */
#include <stdio.h>
#include <ctype.h>
void chline(char ch, int i, int j);
int main(void)
{
    char ch;
    int i, j;

    printf("Enter a character to print: ");
    while (!isprint(ch = getchar()))
    {
        printf("Please enter a printable char.\n");
    }
    printf("Enter two integers for printing: \n");
    while (scanf("%d%d", &i, &j) != 2)
    {
        printf("Please enter two integers.\n");
    }
    chline(ch, i, j);

    return 0;
}

void chline(char ch, int i, int j)
{
    int row, col;

    for(row = 1; row <= 10; row++)
    {
        for (col = 1; col <= j; col++)
        {
            if (col >= i)
                putchar(ch);
            else
                putchar(' ');
        }
        putchar('\n');
    }
}
