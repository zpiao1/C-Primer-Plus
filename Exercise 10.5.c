/* Exercise 10.5.c -- finds the difference between the largest and smallest */
#include <stdio.h>
#include <float.h>
double dist(double ar[], int n);
int main(void)
{
    double array[5] = {61.2, 73.4, 41.0, 95.3, 87.6};
    printf("The difference between the largest"
           " and the smallest number is: %g\n",
           dist(array, 5));

    return 0;
}

double dist(double ar[], int n)
{
    double max = ar[0], min = ar[0];
    int i;

    for (i = 1; i < n; i++)
    {
        if (ar[i] - max > DBL_EPSILON)
            max = ar[i];
        if (min - ar[i] > DBL_EPSILON)
            min = ar[i];
    }

    return (max - min);
}
