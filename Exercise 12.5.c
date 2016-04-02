/* Exercise 12.5.c -- generates and sorts a list of integers */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100
#define RANGE 10
void des_sort(int arr[], int size);
int main(void)
{

    int i;
    int arr[SIZE];

    srand((unsigned int) time(0));
    for (i = 0; i < SIZE; i++)
        arr[i] = rand() % RANGE + 1;

    des_sort(arr, SIZE);

    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", arr[i]);
        if ((i % RANGE) == (RANGE - 1))
            printf("\n");
    }

    return 0;
}

void des_sort(int arr[], int size)
{
    int i, j;
    int temp;

    for (i = 0; i < size - 1; i++)
        for (j = i + 1; j < size; j++)
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}
