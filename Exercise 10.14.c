/* Exercise 10.14.c -- implement Exercise 10.13.c using VLAs */
#include <stdio.h>
#include <float.h>
#define ROWS 3
#define COLS 5
void store(int rows, int cols, double ar[][cols]);
double ave_row(int n, double ar[]);
double ave_all(int rows, int cols, double ar[][cols]);
double max_all(int rows, int cols, double ar[][cols]);
int main(void)
{
    double array[ROWS][COLS];
    int row;

    store(ROWS, COLS, array);
    for (row = 0; row < ROWS; row++)
        printf("The average of Set %d is: %g\n", row + 1, ave_row(COLS, array[row]));
    printf("The average of all values is: %g\n", ave_all(ROWS, COLS, array));
    printf("The largest value is: %g\n", max_all(ROWS, COLS, array));

    return 0;
}

void store(int rows, int cols, double ar[][cols])
{
    int r, c;
    printf("Please enter a 3x5 matrix:\n");
    for (r = 0; r < rows; r++)
        for (c = 0; c < cols; c++)
            scanf("%lf", &ar[r][c]);
}

double ave_row(int n, double ar[])
{
    int i;
    double sum = 0.0;
    for (i = 0; i < n; i++)
        sum += ar[i];

    return (sum / n);
}

double ave_all(int rows, int cols, double ar[][cols])
{
    int r, c;
    double tot = 0.0;
    for (r = 0; r < rows; r++)
        tot += ave_row(cols, ar[r]);

    return (tot / rows);
}

double max_all(int rows, int cols, double ar[][cols])
{
    int r, c;
    double max = ar[0][0];
    for (r = 0; r < rows; r++)
        for (c = 0; c < cols; c++)
            if (ar[r][c] - max > DBL_EPSILON)
                max = ar[r][c];

    return max;
}

