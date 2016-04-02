/* Exercise 15.5.c -- move bits around */
#include <stdio.h>
int rotate_l(int num, int bits);
int main(void)
{
    int value, bits;

    printf("Enter a number: ");
    scanf("%d", &value);

    printf("Enter the number of bits you want to move: ");
    scanf("%d", &bits);

    printf("The new value is: %d\n", rotate_l(value, bits));

    return 0;
}

int rotate_l(int num, int bits)
{
    int count = 0;
    int mask = 0;
    int temp = num;

    // Get the highest bits of the number
    while (temp >= (1 << bits))
    {
        count++;
        temp >>= 1;
    }

    // Construct the mask to cover the other bits
    while (count > 0)
    {
        mask <<= 1;
        mask |= 1;
        count--;
    }

    return (((num & mask) << bits) | temp);
}
