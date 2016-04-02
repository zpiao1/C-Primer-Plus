/* Exercise 15.3.c -- finds the number of on bits in an int */
#include <stdio.h>
int on_bits(int num);

int main(void)
{
    int value;

    printf("Enter the value: ");
    scanf("%d", &value);

    printf("There are %d on bits in %d\n", on_bits(value), value);

    return 0;
}

int on_bits(int num)
{
    int count_on = 0;
    int mask = 1;
    while (num > 0)
    {
        if ((num & mask) == mask)
            count_on++;
        num >>= 1;
    }
    return count_on;
}
