/* Exercise 6.11.c -- stores and prints 8 integers in an array */
#include <stdio.h>
int main(void)
{
    const int SIZE = 8;
    int nums[SIZE];
    int i;

    printf("Enter 8 integers: \n");
    for (i = 0; i < SIZE; i++)
        scanf("%d", &nums[i]);
    for (i = SIZE - 1; i >= 0; i--)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}
