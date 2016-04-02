/* Exercise 12.6.c -- examining the randomness */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
#define RANGE 10

int main(void)
{
    int occur[RANGE];
    int i, rand_num;

    srand((unsigned int) time(0));
    // initialize the array
    for (i = 0; i < RANGE; i++)
        occur[i] = 0;
    // generate the random numbers and do some statistics
    for (i = 0; i < SIZE; i++)
    {
        rand_num = rand() % RANGE + 1;
        occur[rand_num - 1] += 1;
    }
    // show the results
    for (i = 0; i < RANGE; i++)
        printf("%d: %d\n", i + 1, occur[i]);

    return 0;
}
