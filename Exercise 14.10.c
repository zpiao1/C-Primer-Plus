/* Exercise 14.10 -- Use an array of pointers */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 20
typedef void (* v_p_ip_i)(int * arr, int n);
void increasing(int * arr, int n);
void decreasing(int * arr, int n);
void original(int * arr, int n);
void show(int * arr, int n, v_p_ip_i fnp);
int main(void)
{
    int arr[LEN];
    int i;
    v_p_ip_i pfunc;
    v_p_ip_i fparr[3] = {original, increasing, decreasing};

    srand((unsigned int)time(0));

    for (i = 0; i < LEN; i++)
        arr[i] = rand() % 100 + 1;

    puts("Enter the index: 0 for original array");
    puts("1 for increasing order");
    puts("2 for decreasing order");
    scanf("%d", &i);
    pfunc = fparr[i];
    show(arr, LEN, pfunc);

    return 0;
}

void increasing(int * arr, int n)
{
    int i, j;
    int temp;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}
void decreasing(int * arr, int n)
{
    int i, j;
    int temp;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}
void original(int * arr, int n)
{
    // Do nothing
}
void show(int * arr, int n, v_p_ip_i fnp)
{
    int i;
    (*fnp)(arr, n);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
