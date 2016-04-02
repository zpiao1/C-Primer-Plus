/* Exercise 9.6.c -- sorting using function */
#include <stdio.h>
void sort(double * px, double * py, double * pz);
int main(void)
{
    double x, y, z;
    printf("Enter 3 doubles:\n");
    scanf("%lf%lf%lf", &x, &y, &z);
    printf("Before sorting: x = %f, y = %f, z = %f\n", x, y, z);
    sort(&x, &y, &z);
    printf("After sorting: x = %f, y = %f, z = %f\n", x, y, z);

    return 0;
}

void sort(double * px, double * py, double * pz)
{
    double max, middle, min;
    max = (*px > *py ? *px : *py);
    max = (max > *pz ? max : *pz);
    min = (*px < *py ? *px : *py);
    min = (min < *pz ? min : *pz);
    middle = *px + *py + *pz - max - min;
    *px = max;
    *py = middle;
    *pz = min;
}
