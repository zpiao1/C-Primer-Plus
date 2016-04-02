/* Exercise 16.5.c -- simulating lottery */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define SIZE 36
void pick_lottery_num(const int * arr, size_t size, size_t nitems);

int main(void)
{
    int arr[SIZE];
    int i;

    for (i = 0; i < SIZE; i++)
        arr[i] = i + 1;

    pick_lottery_num(arr, SIZE, 7);

    return 0;
}

void pick_lottery_num(const int * arr, size_t size, size_t nitems)
{
    int count = 0;
    int pick;
    int i, nums[SIZE];
    bool picked;

    srand(time(0));
    for (i = 0; i < nitems; i++)
        nums[i] = 0;
    while (count < nitems)
    {
        picked = false;
        pick = arr[(rand() % size)];
        for (i = 0; i < count; i++)
            if (nums[i] == pick)
            {
                picked = true;
                break;
            }
        if (picked)
            continue;
        nums[count] = pick;
        count++;
    }
    puts("The lottery numbers are: ");
    for (i = 0; i < nitems; i++)
        printf("%d ", nums[i]);
    putchar('\n');
}
