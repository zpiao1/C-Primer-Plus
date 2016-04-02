/* Exercise 16.6.c -- qsort() with names structures */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 5

struct names {
    char first[40];
    char last[40];
};

int namecmp(const void * p1, const void * p2);
int main(void)
{
    struct names SM2[NUM] =
    {
        {"Jingyi", "Zhao"},
        {"Shengping", "Cui"},
        {"Wei", "Guo"},
        {"Ziao", "Chen"},
        {"Hailin", "Chen"},
    };

    int i;

    puts("The original list: ");
    for (i = 0; i < NUM; i++)
        printf("%s %s\n", SM2[i].first, SM2[i].last);

    qsort(SM2, 5, sizeof(struct names), namecmp);
    puts("After sorting: ");
    for (i = 0; i < NUM; i++)
        printf("%s %s\n", SM2[i].first, SM2[i].last);

    return 0;
}

int namecmp(const void * p1, const void * p2)
{
    const struct names * s1 = (const struct names *)p1;
    const struct names * s2 = (const struct names *)p2;

    int ret_val;

    ret_val = strcmp(s1->last, s2->last);
    if (ret_val != 0)
        return ret_val;
    else
        return strcmp(s1->first, s2->first);
}

