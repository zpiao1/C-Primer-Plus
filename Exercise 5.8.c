/* Exercise 5.8.c -- Calculates moduli. */
#include <stdio.h>
int main(void)
{
    int operand1, operand2;
    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second operand: ");
    scanf("%d", &operand2);
    printf("Now enter the first operand: ");
    scanf("%d", &operand1);
    printf("%d %% %d is %d\n", operand1, operand2, operand1 % operand2);
    printf("Enter the next number for first operand (<= 0 to quit): ");
    scanf("%d", &operand1);
    while (operand1 > 0)
    {
        printf("%d %% %d is %d\n", operand1, operand2, operand1 % operand2);
        printf("Enter the next number for first operand (<= 0 to quit): ");
        scanf("%d", &operand1);
    }

    return 0;
}
