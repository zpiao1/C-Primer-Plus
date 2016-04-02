/* Exercise 10.10.c -- Adds elements of two arrays correspondingly
   and stores the sum to the correct position in the third
   array */
#include <stdio.h>
void add(int arr1[], int arr2[], int arr_sum[], int n);
void display(int ar[], int n);
int main(void)
{
    int arr1[4] = {2,4,5,8};
    int arr2[4] = {1,0,4,6};
    int arr_sum[4];

    add(arr1, arr2, arr_sum, 4);
    printf("Arr1:\n");
    display(arr1, 4);
    printf("Arr2:\n");
    display(arr2, 4);
    printf("Sum array:\n");
    display(arr_sum, 4);

    return 0;
}

void add(int arr1[], int arr2[], int arr_sum[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        arr_sum[i] = arr1[i] + arr2[i];
}

void display(int ar[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", ar[i]);
    printf("\n");
}
