// pe12-3b.c
// compile with pe12-3a.c
#include <stdio.h>
#include "pe12-3a.h"
int main(void)
{
    int mode = 0, in_mode;
    double distance, fuel;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &in_mode);
    while (in_mode >= 0)
    {
        set_mode(in_mode, &mode);
        get_info(mode, &distance, &fuel);
        show_info(mode, distance, fuel);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &in_mode);
    }
    printf("Done.\n");

    return 0;
}

