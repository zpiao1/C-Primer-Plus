// Exericse 7.10.c -- more on income taxes
#include <stdio.h>
int main(void)
{
    double BASIC = 0.15, EXCESS = 0.28;
    double SINGLE = 17850.0, HOH = 23900.0, MJ = 29750.0, MS = 14875.0;
    double income, tax, limit;
    int choice;

    printf("Choose the category you belong to:\n");
    printf("1 -- Single\n");
    printf("2 -- Head of Household\n");
    printf("3 -- Married, Joint\n");
    printf("4 -- Married, Separate\n");
    while (scanf("%d", &choice) == 1)
    {
        if (choice < 1 || choice > 4)
        {
            printf("Please enter a correct choice!\n");
            continue;
        }
        switch (choice)
        {
            case 1: limit = SINGLE;
                    break;
            case 2: limit = HOH;
                    break;
            case 3: limit = MJ;
                    break;
            case 4: limit = MS;
                    break;
        }
        printf("Enter your income: ");
        scanf("%lf", &income);
        if (income <= limit)
        {
            tax = BASIC * income;
        }
        else
        {
            tax = BASIC * limit + (income - limit) * EXCESS;
        }
        printf("You tax should be %f\n", tax);
        printf("Enter your choice again, letters to quit.\n");
    }

    return 0;
}
