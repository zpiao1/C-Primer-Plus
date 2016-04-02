/* Exercise 4.6.c -- prints a name and the number of chars
   of the first name and the last name */
#include <stdio.h>
#include <string.h>
int main(void)
{
    char first[20], last[20];
    printf("Enter your first name, followed by your last name: ");
    scanf("%s %s", first, last);
    printf("%s %s\n", first, last);
    printf("%*d %*d\n", strlen(first), strlen(first), strlen(last), strlen(last));
    printf("%s %s\n", first, last);
    printf("%-*d %-*d\n", strlen(first), strlen(first), strlen(last), strlen(last));
}
