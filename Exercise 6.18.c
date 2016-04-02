/* Exercise 6.18.c -- Social Networking */
#include <stdio.h>
int main(void)
{
    int friends = 5, week = 1;
    const int DUNBAR = 150;

    friends -= week;
    friends *= 2;
    while (friends <= DUNBAR)
    {
        printf("After week %d: %3d friends left\n", week, friends);
        week++;
        friends -= week;
        friends *= 2;
    }

    return 0;
}
