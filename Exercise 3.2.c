/* Exercise 3.2.c -- prints a character according to the ASCII code provided */
#include <stdio.h>
int main(void)
{
    char ch;
    printf("Enter the ASCII code of the character: ");
    scanf("%d", &ch);
    printf("The corresponding character is: %c\n", ch);
    return 0;
}
