#include <stdio.h>
#define UNDERLINE_MASK  (0x1 << 1)
#define ITALIC_MASK     (0x1 << 2)
#define BOLD_MASK       (0x1 << 3)
#define ALIGN_MASK      (0x3 << 6)
#define FONT_SIZE_MASK  (0x7F << 9)
#define FONT_ID_MASK    (0xFF << 16)

void show_font(unsigned long fi);
void change_font(unsigned long * fi);
void change_size(unsigned long * fi);
void change_align(unsigned long * fi);
void toggle_bold(unsigned long * fi);
void toggle_italic(unsigned long * fi);
void toggle_underline(unsigned long * fi);
void show_menu(void);
int main(void)
{
    unsigned long font_info = 0x11800;
    // 0000 0001 0001 1000 0000 0000
    char choice;

    show_font(font_info);
    show_menu();
    choice = getchar();
    while (choice != 'q')
    {
        while (getchar() != '\n')
            continue;
        switch (choice)
        {
            case 'f': change_font(&font_info); break;
            case 's': change_size(&font_info); break;
            case 'a': change_align(&font_info); break;
            case 'b': toggle_bold(&font_info); break;
            case 'i': toggle_italic(&font_info); break;
            case 'u': toggle_underline(&font_info); break;
            default: printf("Unknown command!\n"); break;
        }
        show_font(font_info);
        show_menu();
        choice = getchar();
    }

    puts("Bye!");

    return 0;
}

void show_font(const unsigned long fi)
{
    puts("  ID SIZE ALIGNMENT   B   I   U");
    printf("%4d ", (fi & FONT_ID_MASK) >> 16);
    printf("%4d ", (fi & FONT_SIZE_MASK) >> 9);
    switch((fi & ALIGN_MASK) >> 6)
    {
        case 0: printf("%6s     ", "left"); break;
        case 1: printf("%6s     ", "center"); break;
        case 2: printf("%6s     ", "right"); break;
        default: printf("           ");
    }
    printf("%3s ", ((fi & BOLD_MASK) >> 3 ? "on" : "off"));
    printf("%3s ", ((fi & ITALIC_MASK) >> 2 ? "on" : "off"));
    printf("%3s\n\n\n", ((fi & UNDERLINE_MASK) >> 1 ? "on" : "off"));
}

void change_font(unsigned long * fi)
{
    int id;
    int mask = 0xFF;
    printf("Enter font id (0-225): ");
    scanf("%d", &id);
    while (getchar() != '\n')
        continue;
    *fi = (*fi) & ~(FONT_ID_MASK);  // clear the bits
    *fi |= ((id & mask) << 16);  // assign new bits
    printf("\n");
}

void change_size(unsigned long * fi)
{
    int size;
    int mask = 0x7F;
    printf("Enter font size (0-127): ");
    scanf("%d", &size);
    while (getchar() != '\n')
        continue;
    *fi = (*fi) & ~(FONT_SIZE_MASK);    // clear the bits
    *fi |= ((size & mask) << 9);     // assign new bits
    printf("\n");
}

void change_align(unsigned long * fi)
{
    char align;
    int align_int;
    puts("Select alignment:");
    puts("l)left   c)center   r)right");
    align = getchar();
    while (getchar() != '\n')
        continue;
    switch (align)
    {
        case 'l': align_int = 0; break;
        case 'c': align_int = 1; break;
        case 'r': align_int = 2; break;
        default: printf("Wrong alignment!\n"); return;
    }
    *fi = (*fi) & ~(ALIGN_MASK);
    *fi |= (align_int << 6);
}
void toggle_bold(unsigned long * fi)
{
    *fi ^= 0x8;
}
void toggle_italic(unsigned long * fi)
{
    *fi ^= 0x4;
}
void toggle_underline(unsigned long * fi)
{
    *fi ^= 0x2;
}
void show_menu(void)
{
    puts("f)change font    s)change size    a)change alignment");
    puts("b)toggle bold    i)toggle italic  u)toggle underline");
    puts("q)quit");
}

