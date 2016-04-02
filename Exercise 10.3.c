/* Exercise 10.3.c -- find the largest values in an array-of-int */
#include <stdio.h>
int largest(int ar[], int n);
int main(void)
{
    int array[5] = {1, 10, 38, 23, 6};
    printf("The largest value is %d\n", largest(array, 5));

    return 0;
}

int largest(int ar[], int n)
{
    int i, max = ar[0];
    for (i = 1; i < n; i++)
    {
        if (ar[i] > max)
            max = ar[i];
    }

    return max;
}
