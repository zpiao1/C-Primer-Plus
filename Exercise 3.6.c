/* Exercise 3.6.c -- convert the number of quart of water to number of
    molecule */
#include <stdio.h>
int main(void)
{
    long double molar_mass = 3e-23;
    long double mass_of_quart = 950.0;
    int quarts;
    printf("Enter the quarts of water: ");
    scanf("%d", &quarts);
    long double molecules = mass_of_quart * quarts / molar_mass;
    printf("There are %llf molecules\n", molecules);

    return 0;
}
