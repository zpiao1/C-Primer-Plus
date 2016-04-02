/* Exercise 10.8.c -- slicing an array */
#include <stdio.h>
void slice(double * ptar, double * psrc, int n);
void display(double ar[], int n);
int main(void)
{
    double source[7] = {3.0, 5.0, 7.0, 9.0, 11.0, 2.5, 4.5};
    double target[3];

    slice(target, source + 2, 3);
    display(source, 7);
    display(target, 3);

    return 0;
}

void slice(double * ptar, double * psrc, int n)
{
    int i;
    for (i = 0; i < n; i++)
        *(ptar + i) = *(psrc + i);
}

void display(double ar[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%g ", ar[i]);
    printf("\n");
}
