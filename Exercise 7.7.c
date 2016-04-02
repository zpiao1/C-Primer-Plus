// Exercise 7.7.c -- Salaries and taxes calculation
#include <stdio.h>
#define BASIC_PAY 10.00
#define OVERTIME_RATE 1.5
#define FIRST_TAX 0.15
#define SECOND_TAX 0.2
#define THIRD_TAX 0.25
#define LIMIT_HRS 40
#define LIMIT_PAY1 300
#define LIMIT_PAY2 150
int main(void)
{
    double hours, gross_pay, taxes, net_pay;

    printf("Enter the hours of work: ");
    scanf("%lf", &hours);
    if (hours <= LIMIT_HRS)
        gross_pay = BASIC_PAY * hours;
    else
        gross_pay = BASIC_PAY * LIMIT_HRS + (hours - LIMIT_HRS) * BASIC_PAY * OVERTIME_RATE;
    if (gross_pay <= LIMIT_PAY1)
        taxes = gross_pay * FIRST_TAX;
    else if (gross_pay <= (LIMIT_PAY1 + LIMIT_PAY2))
        taxes = LIMIT_PAY1 * FIRST_TAX + (gross_pay - LIMIT_PAY1) * SECOND_TAX;
    else
        taxes = LIMIT_PAY1 * FIRST_TAX + LIMIT_PAY2 * SECOND_TAX + (gross_pay - LIMIT_PAY1 - LIMIT_PAY2) * THIRD_TAX;
    net_pay = gross_pay - taxes;

    printf("Gross pay = %f, taxes = %f, net pay = %f\n", gross_pay, taxes, net_pay);

    return 0;
}
