/* Exercise 5.9.c -- converts temperatures */
#include <stdio.h>
void Temperatures(double degreeF);
int main(void)
{
    double fahrenheit;
    printf("Enter a Fahrenheit temperature: ");
    scanf("%lf", &fahrenheit);
    Temperatures(fahrenheit);
    printf("Enter the next Fahrenheit temperature (nonnumeric to quit): ");
    while (scanf("%lf", &fahrenheit) == 1)
    {
        Temperatures(fahrenheit);
        printf("Enter the next Fahrenheit temperature (nonnumeric to quit): ");
    }


    return 0;
}

void Temperatures(double degreeF)
{
    const double F_TO_C_MUL = 5.0 / 9.0;
    const double F_TO_C_SUB = 32.0;
    const double C_TO_K_ADD = 273.16;
    double degreeC = F_TO_C_MUL * (degreeF - F_TO_C_SUB);
    double degreeK = degreeC + C_TO_K_ADD;

    printf("%f Fahrenheit = %f Celsius = %f Kelvin\n", degreeF, degreeC, degreeK);


}