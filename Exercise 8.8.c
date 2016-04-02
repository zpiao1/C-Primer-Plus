// Exercise 8.8.c -- command line calculator
#include <stdio.h>
#include <float.h>     // for FLOAT_EPSILON
#include <math.h>       // for fabs()
float get_number(void);
void add(void);
void subtract(void);
void multiply(void);
void divide(void);
int main(void)
{
    char choice;

    printf("Enter the operation of your choice:\n");
    printf("a. add           s. subtract\n");
    printf("m. multiply      d. divide\n");
    printf("q. quit\n");
    while ((choice = getchar()) != 'q')
    {
        switch (choice)
        {
            case 'a' : add();
                  break;
            case 's' : subtract();
                  break;
            case 'm' : multiply();
                  break;
            case 'd' : divide();
                  break;
            default : printf("I can only understand the above"
                             "options.\n");
        }
        printf("Enter the operation of your choice:\n");
        printf("a. add           s. subtract\n");
        printf("m. multiply      d. divide\n");
        printf("q. quit\n");
        while (getchar() != '\n')
            continue;
    }
    printf("Bye.\n");

    return 0;
}

float get_number(void)
{
    float num;
    char ch;

    while (scanf("%f", &num) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
    }
    return num;

}

void add(void)
{
    float operand1, operand2;

    printf("Enter first number: ");
    operand1 = get_number();
    printf("Enter second number: ");
    operand2 = get_number();
    printf("%g + %g = %g\n", operand1, operand2, operand1 + operand2);
}

void subtract(void)
{
    float operand1, operand2;

    printf("Enter first number: ");
    operand1 = get_number();
    printf("Enter second number: ");
    operand2 = get_number();
    printf("%g - %g = %g\n", operand1, operand2, operand1 - operand2);
}

void multiply(void)
{
    float operand1, operand2;

    printf("Enter first number: ");
    operand1 = get_number();
    printf("Enter second number: ");
    operand2 = get_number();
    printf("%g * %g = %g\n", operand1, operand2, operand1 * operand2);
}

void divide(void)
{
    float operand1, operand2;

    printf("Enter first number: ");
    operand1 = get_number();
    printf("Enter second number: ");
    operand2 = get_number();
    while (fabs(operand2) <= FLT_EPSILON)
    {
        printf("Enter a number other than 0: ");
        operand2 = get_number();
    }

    printf("%g / %g = %g\n", operand1, operand2, operand1 / operand2);
}
