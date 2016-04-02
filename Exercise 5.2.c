/* Exercise 5.2.c -- prints 10 consecutive integers */
#include <stdio.h>
int main(void)
{
    int num, count;
    printf("Enter the number: ");
    scanf("%d", &num);
    count = num;
    while (count <= num + 10)
    {
        printf("%d\t", count);
        count++;
    }

    return 0;
}
