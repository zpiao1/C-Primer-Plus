/* Exercise 15.4.c -- return the required bit */
#include <stdio.h>

int bit_on_pos(int num, int pos);

int main(void)
{
    int num, pos;

    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter the position: ");
    scanf("%d", &pos);

    printf("Bit %d of %d is %d\n", pos, num, bit_on_pos(num, pos));

    return 0;
}

int bit_on_pos(int num, int pos)
{
    int mask = 1;

    return ((num >> pos) & mask);
}
