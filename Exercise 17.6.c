/* Exercise 17.6.c -- using binary search technique in arrays */
#include <stdio.h>
#define MAXSIZE 50
int seek_int(int * arr, int size, int sk_val);

int main(void)
{
    int arr[MAXSIZE];
    int i;
    int seek_value;

    for (i = 0; i < MAXSIZE; i++)
        arr[i] = i * 3;

    printf("Enter the value you want to find: ");
    scanf("%d", &seek_value);

    if (seek_int(arr, MAXSIZE, seek_value) == 1)
        printf("%d is found!\n", seek_value);
    else
        printf("%d is not in the array!\n", seek_value);



    return 0;
}

int seek_int(int * arr, int size, int sk_val)
{
    int half_size;
    if (size < 1)
        return 0;
    half_size = size / 2;
    if (*(arr + half_size) == sk_val)
        return 1;
    else if (*(arr + half_size) < sk_val)
        return seek_int(arr + half_size + 1, size - half_size - 1, sk_val);
    else
        return seek_int(arr, half_size, sk_val);

}
