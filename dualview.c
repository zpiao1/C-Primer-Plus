/* dualview.c -- bit fields and bitwise operators */
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
/* BIT_FIELD CONSTANTS */
/* line styles      */
#define SOLID   0   // 0000
#define DOTTED  1   // 0001
#define DASHED  2   // 0010
/* primary colors   */
#define BLUE    4   // 0100
#define GREEN   2   // 0010
#define RED     1   // 0001
/* mixed colors     */
#define BLACK   0                       // 0000
#define YELLOW  (RED | GREEN)           // 0011
#define MAGENTA (RED | BLUE)            // 0101
#define CYAN    (GREEN | BLUE)          // 0110
#define WHITE   (RED | GREEN | BLUE)    // 0111

/* BITWISE CONSTANTS    */
#define OPAQUE          0x1     // 0000 0000 0000 0001
#define FILL_BLUE       0x8     // 0000 0000 0000 1000
#define FILL_GREEN      0x4     // 0000 0000 0000 0100
#define FILL_RED        0x2     // 0000 0000 0000 0010
#define FILL_MASK       0xE     // 0000 0000 0000 1110
#define BORDER          0x100   // 0000 0001 0000 0000
#define BORDER_BLUE     0x800   // 0000 1000 0000 0000
#define BORDER_GREEN    0x400   // 0000 0100 0000 0000
#define BORDER_RED      0x200   // 0000 0010 0000 0000
#define BORDER_MASK     0xE00   // 0000 1110 0000 0000
#define B_SOLID         0       // 0000 0000 0000 0000
#define B_DOTTED        0x1000  // 0001 0000 0000 0000
#define B_DASHED        0x2000  // 0010 0000 0000 0000
#define STYLE_MASK      0x3000  // 0011 0000 0000 0000

const char * colors[8] = {"black", "red", "green", "yellow",
    "blue", "magenta", "cyan", "white"};
struct box_props {
    bool opaque                 : 1;
    unsigned int fill_color     : 3;
    unsigned int                : 4;
    bool show_border            : 1;
    unsigned int border_color   : 3;
    unsigned int border_style   : 2;
    unsigned int                : 2;
};

union Views     /* look at data as struct or as unsigned short  */
{
    struct box_props st_view;
    unsigned short us_view;
};

void show_settings(const struct box_props * pb);
void show_settings1(unsigned short);
char * itobs(int n, char * ps);

int main(void)
{
    /* create Views object, initialize struct box view  */
    union Views box = {{true, YELLOW, true, GREEN, DASHED}};
    char bin_str[8 * sizeof(unsigned int) + 1];

    printf("Original box settings:\n");
    show_settings(&box.st_view);
    printf("\nBox settings using unsigned int view:\n");
    show_settings1(box.us_view);

    printf("bits are %s\n",
           itobs(box.us_view, bin_str));
    box.us_view &= ~FILL_MASK;      /* clear fill bits  */
    box.us_view |= (FILL_BLUE | FILL_GREEN);    /* reset fill   */
    box.us_view ^= OPAQUE;                  /* toggle opacity   */
    box.us_view |= BORDER_RED;              /* wrong approach   */
    box.us_view &= ~STYLE_MASK;             /* clear style bits */
    box.us_view |= B_DOTTED;            /* set style to dotted  */
    printf("\nModified box settings:\n");
    show_settings(&box.st_view);
    printf("\nBox settings using unsigned int view:\n");
    show_settings1(box.us_view);
    printf("bits are %s\n",
           itobs(box.us_view, bin_str));

    return 0;
}

void show_settings(const struct box_props * pb)
{
    printf("Box is %s.\n",
           pb->opaque == true ? "opaque" : "transparent");
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    printf("Border %s.\n",
           pb->show_border ==  true ? "shown" : "not shown");
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf("The border style is ");
    switch (pb->border_style)
    {
        case SOLID  : printf("solid.\n"); break;
        case DOTTED : printf("dotted.\n"); break;
        case DASHED : printf("dashed.\n"); break;
        default     : printf("unknown type.\n");
    }
}
void show_settings1(unsigned short us)
{
    printf("box is %s.\n",
           (us & OPAQUE) == OPAQUE ? "opaque" : "transparent");
    printf("The fill color is %s.\n",
           colors[(us >> 1) & 07]);
    printf("Border %s.\n",
           (us & BORDER) == BORDER ? "shown" : "not shown");
    switch (us & STYLE_MASK)
    {
        case B_SOLID    : printf("solid.\n"); break;
        case B_DOTTED   : printf("dotted.\n"); break;
        case B_DASHED   : printf("dashed.\n"); break;
        default         : printf("unknown type.\n");
    }
    printf("The border color is %s.\n",
           colors[(us >> 9) & 07]);
}

char * itobs(int n, char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (0x1 & n) + '0';
    ps[size] = '\0';

    return ps;
}
