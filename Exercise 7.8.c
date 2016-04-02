// Exercise 7.8.c -- Salaries and taxes calculation with various choice of rate
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
    printf("1) $8.75/hr                         2) $9.33/hr\n");
    printf("3) $10.00/hr                        4) $11.20/hr\n");
    printf("5) quit\n");
    printf("*****************************************************************\n");

    while ((choice = getchar()) != '5')
    {
        if (choice > '4' || choice < '1')
        {
            getchar();
            printf("Please enter the correct choice (1) - (5):\n");
            continue;
        }
        else
        {
            switch (choice)
            {
                case '1': basic_pay = BASIC_PAY1;
                          break;
                case '2': basic_pay = BASIC_PAY2;
                          break;
                case '3': basic_pay = BASIC_PAY3;
                          break;
                case '4': basic_pay = BASIC_PAY4;
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

            printf("Gross pay = %f, taxes = %f, net pay = %f\n", gross_pay, taxes, net_pay);
            printf("Choose (1) - (5) again to decide whether to continue:\n");
        }
    }

    return 0;
}

