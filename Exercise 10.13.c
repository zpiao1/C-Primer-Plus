/* Exercise 10.13.c -- stores and analyses user input doubles */
#include <stdio.h>
#include <float.h>
#define ROWS 3
#define COLS 5
void store(double ar[][COLS], int rows);
double ave_row(double ar[], int n);
double ave_all(double ar[][COLS], int rows);
double max_all(double ar[][COLS], int rows);
int main(void)
{
    double array[ROWS][COLS];
    int row;

    store(array, ROWS);
    for (row = 0; row < ROWS; row++)
        printf("The average of Set %d is: %g\n", row + 1, ave_row(array[row], COLS));
    printf("The average of all values is: %g\n", ave_all(array, ROWS));
    printf("The largest value is: %g\n", max_all(array, ROWS));

    return 0;
}

void store(double ar[][COLS], int rows)
{
    int r, c;
    printf("Please enter a 3x5 matrix:\n");
    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            scanf("%lf", &ar[r][c]);
}

double ave_row(double ar[], int n)
{
    int i;
    double sum = 0.0;
    for (i = 0; i < n; i++)
        sum += ar[i];

    return (sum / n);
}

double ave_all(double ar[][COLS], int rows)
{
    int r, c;
    double tot = 0.0;
    for (r = 0; r < rows; r++)
        tot += ave_row(ar[r], COLS);

    return (tot / ROWS);
}

double max_all(double ar[][COLS], int rows)
{
    int r, c;
    double max = ar[0][0];
    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            if (ar[r][c] - max > DBL_EPSILON)
                max = ar[r][c];

    return max;
}
