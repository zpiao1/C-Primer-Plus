/* Exercise 12.7.c -- Many dices */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void throw_dice(int sets, int sides, int dice);
void roll(int sides, int dice);
int main(void)
{
    int sets, sides, dice;

    srand((unsigned int)time(0));
    printf("Enter the number of sets; enter q to stop: ");
    while (scanf("%d", &sets) == 1 && sets > 0)
    {
        printf("How many sides and how many dice? ");
        scanf("%d %d", &sides, &dice);
        throw_dice(sets, sides, dice);
        printf("How many sets? Enter q to stop: ");
    }

    return 0;
}

void throw_dice(int sets, int sides, int dice)
{
    int count;

    printf("Here are %d sets of %d %d-sided throws.\n",
           sets, dice, sides);
    for (count = 1; count <= sets; count++)
    {
        roll(sides, dice);
    }
    printf("\n");
}

void roll(int sides, int dice)
{
    int total = 0, i;
    int result;
    for (i = 0; i < dice; i++)
    {
        result = rand() % sides + 1;
        // printf("%d\n", result);
        total += result;
    }
    printf("%4d", total);
}
