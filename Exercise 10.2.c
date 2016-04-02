/* Exercise 10.2.c -- copying array contents */
#include <stdio.h>
void copy_arr(double tar[], double src[], int n);
void copy_ptr(double * ptar, double * psrc, int n);
void copy_ptrs(double * ptar, double * srcstart, double * srcend);
void display(double ar[], int n);
int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);

    display(source, 5);
    display(target1, 5);
    display(target2, 5);
    display(target3, 5);

    return 0;
}

void copy_arr(double tar[], double src[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        tar[i] = src[i];
}

void copy_ptr(double * ptar, double * psrc, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        *ptar = *psrc;
        ptar++;
        psrc++;
    }
}

void copy_ptrs(double * ptar, double * srcstart, double * srcend)
{
    while (srcstart < srcend)
    {
        *ptar = *srcstart;
        ptar++;
        srcstart++;
    }
}

void display(double ar[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%g ", ar[i]);
    printf("\n");
}
