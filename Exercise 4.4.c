/* Exercise 4.4.c -- prints a person's name and his height in feet */
#include <stdio.h>
int main(void)
{
    char name[20];
    float inches, feet;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your height in inches: ");
    scanf("%f", &inches);
    feet = inches / 12.0;
    printf("%s, you are %.3f feet tall\n", name, feet);

    return 0;
}
