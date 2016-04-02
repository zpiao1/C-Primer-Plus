/* Exercise 10.4.c -- find the index of the max in an array-of-double */
#include <stdio.h>
#include <float.h>
int max_index(double ar[], int n);
int main(void)
{
    double array[5] = {15.3, 6.8, 75.9, 64.2, 33.7};
    printf("The index of the largest value is: %d\n", max_index(array, 5));

    return 0;
}

int max_index(double ar[], int n)
{
    int i, max_in = 0;
    double max = ar[0];
    for (i = 1; i <= n; i++)
    {
        if (ar[i] - max > DBL_EPSILON)
        {
            max = ar[i];
            max_in = i;
        }
    }

    return max_in;
}
