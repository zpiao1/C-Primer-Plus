/* Exercise 10.7.c -- copying 2D arrays */
#include <stdio.h>
void copy_2d(double (*ptar)[4], double (*psrc)[4], int rows);
void copy_ptrs(double * ptar, double * psrc, double * srcend);
void display(double ar[][4], int rows);
int main(void)
{
    double source[3][4] = {
        {1.3, 5.7, 9.1, 3.5},
        {2.4, 6.8, 0.2, 4.6},
        {1.9, 2.8, 3.7, 4.6},
    };

    double target[3][4];
    copy_2d(target, source, 3);
    printf("Source:\n");
    display(source, 3);
    printf("Target:\n");
    display(target, 3);

    return 0;
}

void copy_ptr(double * ptar, double * psrc, double * srcend)
{
    while (psrc < srcend)
    {
        *ptar = *psrc;
        ptar++;
        psrc++;
    }
}

void copy_2d(double (*ptar)[4], double (*psrc)[4], int rows)
{
    int i;
    for (i = 0; i < rows; i++)
    {
        copy_ptr(*(ptar + i), *(psrc + i), *(psrc + i) + 4);
    }
}

void display(double ar[][4], int rows)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%g ", ar[i][j]);
        printf("\n");
    }
}
