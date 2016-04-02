/* Exercise 12.1.c -- rewritten version of Listing
   12.4 */
#include <stdio.h>
void critic(int * punits);
int main(void)
{
    int units;

    printf("How many pounds to firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic(&units);
    printf("You must have looked it up!\n");

    return 0;
}

void critic(int * punits)
{
    printf("No luck, my friend. Try again.\n");
    scanf("%d", punits);
}
