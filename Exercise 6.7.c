/* Exercise 6.7.c -- prints a string backward */
#include <stdio.h>
#include <string.h>
int main(void)
{
    const int MAX = 20;
    char word[MAX];
    int i;

    printf("Enter the word (<20 letters): ");
    scanf("%s", word);
    for (i = strlen(word) - 1; i >= 0; i--)
        printf("%c", word[i]);

    return 0;
}
