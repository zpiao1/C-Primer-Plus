// Exercise 7.11.c -- A grocery store
#include <stdio.h>

int main(void)
{
    char choice;
    double wt_artichokes = 0, wt_beets = 0, wt_carrots = 0, weight;
    double cost_artichokes, cost_beets, cost_carrots;
    double total_charge, discount, ship_charge, grand_total;

    const double ARTICHOKES = 2.05, BEETS = 1.15, CARROTS = 1.09;
    const double DISC_RATE = 0.05, DISC_LIMIT = 100, SHIP_CHARGE1 = 6.50;
    const double WT_LIMIT1 = 5, SHIP_CHARGE2 = 14, WT_LIMIT2 = 20, SHIP_CHARGE3_PER_LB = 0.50;

    printf("Enter the order, q to place the order:\n");
    printf("a: artichokes\tb: beets\tc: carrots\n");
    while ((choice = getchar()) != 'q')
    {
        if (choice < 'a' || choice > 'c')
        {
            printf("Please enter correct order!\n");
            continue;
        }
        switch (choice)
        {
            case 'a': printf("Enter the weight of artichokes: ");
                      scanf("%lf", &weight);
                      wt_artichokes += weight;
                      break;
            case 'b': printf("Enter the weight of beets: ");
                      scanf("%lf", &weight);
                      wt_beets += weight;
                      break;
            case 'c': printf("Enter the weight of carrots: ");
                      scanf("%lf", &weight);
                      wt_carrots += weight;
                      break;
        }
        printf("Enter a new order, or q to quit\n");
        getchar();
    }

    cost_artichokes = wt_artichokes * ARTICHOKES;
    cost_beets = wt_beets * BEETS;
    cost_carrots = wt_carrots * CARROTS;
    total_charge = cost_artichokes + cost_beets + cost_carrots;
    if (total_charge >= DISC_LIMIT)
        discount = total_charge * DISC_RATE;
    else
        discount = 0.0;
    weight = wt_artichokes + wt_beets + wt_carrots;
    if (weight <= WT_LIMIT1)
        ship_charge = SHIP_CHARGE1;
    else if (weight <= WT_LIMIT2)
        ship_charge = SHIP_CHARGE2;
    else
        ship_charge = SHIP_CHARGE2 + SHIP_CHARGE3_PER_LB * (weight - WT_LIMIT2);
    grand_total = total_charge - discount + ship_charge;

    printf("Vegetable | Cost per pound | Pounds ordered | Cost for the vegetable\n");
    printf("--------------------------------------------------------------------\n");
    printf("Artichokes  %14.2f   %14g   %22.2f\n", ARTICHOKES, wt_artichokes, cost_artichokes);
    printf("Beets       %14.2f   %14g   %22.2f\n", BEETS, wt_beets, cost_beets);
    printf("Carrots     %14.2f   %14g   %22.2f\n", CARROTS, wt_carrots, cost_carrots);
    printf("Total cost: %.2f\n", total_charge);
    if (discount > 1E-7)
        printf("Discount: %.2f\n", discount);
    printf("Shipping charge: %.2f\n", ship_charge);
    printf("Grand total: %.2f\n", grand_total);

    return 0;
}
