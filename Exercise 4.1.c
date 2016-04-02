/* Exercise 4.1.c -- asks for first name and last name
   and prints in the format "last, first". */
#include <stdio.h>
int main(void)
{
    char first[20], last[20];

    printf("Enter your first name: ");
    scanf("%s", first);
    printf("Enter your last name: ");
    scanf("%s", last);

    printf("%s, %s", last, first);
    return 0;

}
