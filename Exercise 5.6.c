/* Exercise 5.6.c -- Calculate the sum of squares up to n */
#include <stdio.h>
int main(void)                      /* finds sum of first 20 integers   */
{
    int count, sum, n;              /* declaration statement            */
    printf("Enter the biggest value your want to add up to: ");
    scanf("%d", &n);
    count = 0;                      /* assignment statement             */
    sum = 0;                        /* ditto                            */
    while (count++ < n)             /* while                            */
        sum = sum + count * count;  /*      statement                   */
    printf("sum = %d\n", sum);      /* function statement               */

    return 0;                       /* return statement                 */
}
