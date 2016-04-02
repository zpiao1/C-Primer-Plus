/* Exercise 10.9.c -- Use VLA functions to copy and display */
#include <stdio.h>
void copy(int rows, int cols, int tar[][cols], int src[][cols]);
void display(int rows, int cols, int ar[][cols]);
int main(void)
{
    int source[3][5] = {
        {35,65,41,32,54},
        {23,46,84,36,51},
        {71,82,99,42,93}
    };

    int target[3][5];
    copy(3, 5, target, source);
    printf("Source:\n");
    display(3, 5, source);
    printf("Target:\n");
    display(3, 5, target);

    return 0;
}

void copy(int rows, int cols, int tar[][cols], int src[][cols])
{
    int r, c;
    for (r = 0; r < rows; r++)
        for (c = 0; c < cols; c++)
            tar[r][c] = src[r][c];
}

void display(int rows, int cols, int ar[][cols])
{
    int r, c;
    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < cols; c++)
            printf("%d ", ar[r][c]);
        printf("\n");
    }
}
