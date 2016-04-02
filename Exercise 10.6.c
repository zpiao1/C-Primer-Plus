/* Exercise 10.6.c -- reverses an array-of-double */
#include <stdio.h>
void reverse(double ori[], double rev[], int n);
int main(void)
{
    double ar[5] = {95.3, 87.6, 73.4, 61.2, 41.0};
    double rev_ar[5];
    int i;
    reverse(ar, rev_ar, 5);
    for (i = 0; i < 5; i++)
        printf("%g ", ar[i]);
    printf("\n");
    for (i = 0; i < 5; i++)
        printf("%g ", rev_ar[i]);
    printf("\n");

    return 0;
}

void reverse(double ori[], double rev[], int n)
{
    int index;
    for (index = 0; index < n; index++)
        rev[n - 1 - index] = ori[index];
}
