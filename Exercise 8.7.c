// Exercise 8.7.c -- Uses character to indicate the menu
#include <stdio.h>
#define BASIC_PAY1 8.75
#define BASIC_PAY2 9.33
#define BASIC_PAY3 10.00
#define BASIC_PAY4 11.20
#define OVERTIME_RATE 1.5
#define FIRST_TAX 0.15
#define SECOND_TAX 0.2
#define THIRD_TAX 0.25
#define LIMIT_HRS 40
#define LIMIT_PAY1 300
#define LIMIT_PAY2 150
int main(void)
{
    double hours, gross_pay, taxes, net_pay, basic_pay;
    char choice;

    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr                         b) $9.33/hr\n");
    printf("c) $10.00/hr                        d) $11.20/hr\n");
    printf("q) quit\n");
    printf("*****************************************************************\n");

    while ((choice = getchar()) != 'q')
    {
        if (choice > 'd' || choice < 'a')
        {
            while (getchar() != '\n')
                continue;
            printf("Please enter the correct choice a) - d):\n");
            continue;
        }
        else
        {
            switch (choice)
            {
                case 'a': basic_pay = BASIC_PAY1;
                          break;
                case 'b': basic_pay = BASIC_PAY2;
                          break;
                case 'c': basic_pay = BASIC_PAY3;
                          break;
                case 'd': basic_pay = BASIC_PAY4;
                          break;
            }
            printf("Enter the hours of work: ");
            scanf("%lf", &hours);
            if (hours <= LIMIT_HRS)
                gross_pay = basic_pay * hours;
            else
                gross_pay = basic_pay * LIMIT_HRS + (hours - LIMIT_HRS) * basic_pay * OVERTIME_RATE;
            if (gross_pay <= LIMIT_PAY1)
                taxes = gross_pay * FIRST_TAX;
            else if (gross_pay <= (LIMIT_PAY1 + LIMIT_PAY2))
                taxes = LIMIT_PAY1 * FIRST_TAX + (gross_pay - LIMIT_PAY1) * SECOND_TAX;
            else
                taxes = LIMIT_PAY1 * FIRST_TAX + LIMIT_PAY2 * SECOND_TAX + (gross_pay - LIMIT_PAY1 - LIMIT_PAY2) * THIRD_TAX;
            net_pay = gross_pay - taxes;

            printf("Gross pay = %.2f, taxes = %.2f, net pay = %.2f\n", gross_pay, taxes, net_pay);
            printf("Choose a) - d) again to decide whether to continue:\n");
        }
        while (getchar() != '\n')
                continue;
    }

    return 0;
}

