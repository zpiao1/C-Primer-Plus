/* Exercise 10.11.c -- prints and doubles and 2D array */
#include <stdio.h>
void arrx2(int tar[][5], int src[][5], int rows);
void display(int ar[][5], int rows);
int main(void)
{
    int array[3][5] = {
        {35,65,41,32,54},
        {23,46,84,36,51},
        {71,82,99,42,93}
    };
    int arrayx2[3][5];

    arrx2(arrayx2, array, 3);
    printf("Original array:\n");
    display(array, 3);
    printf("Doubled array:\n");
    display(arrayx2, 3);

    return 0;
}

void arrx2(int tar[][5], int src[][5], int rows)
{
    int r, c;
    for (r = 0; r < rows; r++)
        for (c = 0; c < 5; c++)
            tar[r][c] = src[r][c] * 2;
}

void display(int ar[][5], int rows)
{
    int r, c;
    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < 5; c++)
            printf("%d ", ar[r][c]);
        printf("\n");
    }
}
