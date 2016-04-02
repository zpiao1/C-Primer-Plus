/* Exercise 15.6.c -- Bit-field structure to store text info */
#include <stdio.h>
#include <stdbool.h>
struct font_info {
    unsigned int font_id    : 8;
    unsigned int font_size  : 7;
    unsigned int            : 1;
    unsigned int align      : 2;
    unsigned int            : 2;
    bool bold               : 1;
    bool italic             : 1;
    bool underline          : 1;
    unsigned int            : 1;
};

void show_font(const struct font_info * fi);
void change_font(struct font_info * fi);
void change_size(struct font_info * fi);
void change_align(struct font_info * fi);
void toggle_bold(struct font_info * fi);
void toggle_italic(struct font_info * fi);
void toggle_underline(struct font_info * fi);
void show_menu(void);
int main(void)
{
    struct font_info font = {1, 12, 0, false, false, false};
    char choice;

    show_font(&font);
    show_menu();
    choice = getchar();
    while (choice != 'q')
    {
        while (getchar() != '\n')
            continue;
        switch (choice)
        {
            case 'f': change_font(&font); break;
            case 's': change_size(&font); break;
            case 'a': change_align(&font); break;
            case 'b': toggle_bold(&font); break;
            case 'i': toggle_italic(&font); break;
            case 'u': toggle_underline(&font); break;
            default: printf("Unknown command!\n"); break;
        }
        show_font(&font);
        show_menu();
        choice = getchar();
    }

    puts("Bye!");

    return 0;
}

void show_font(const struct font_info * fi)
{
    puts("  ID SIZE ALIGNMENT   B   I   U");
    printf("%4d ", fi->font_id);
    printf("%4d ", fi->font_size);
    switch(fi->align)
    {
        case 0: printf("%6s     ", "left"); break;
        case 1: printf("%6s     ", "center"); break;
        case 2: printf("%6s     ", "right"); break;
        default: printf("           ");
    }
    printf("%3s ", (fi->bold ? "on" : "off"));
    printf("%3s ", (fi->italic ? "on" : "off"));
    printf("%3s\n\n\n", (fi->underline) ? "on" : "off");
}

void change_font(struct font_info * fi)
{
    int id;
    int mask = 0xFF;
    printf("Enter font id (0-225): ");
    scanf("%d", &id);
    while (getchar() != '\n')
        continue;
    fi->font_id = (id & mask);
    printf("\n");
}

void change_size(struct font_info * fi)
{
    int size;
    int mask = 0x7F;
    printf("Enter font size (0-127): ");
    scanf("%d", &size);
    while (getchar() != '\n')
        continue;
    fi->font_size = (size & mask);
    printf("\n");
}

void change_align(struct font_info * fi)
{
    char align;
    puts("Select alignment:");
    puts("l)left   c)center   r)right");
    align = getchar();
    while (getchar() != '\n')
        continue;
    switch (align)
    {
        case 'l': fi->align = 0; break;
        case 'c': fi->align = 1; break;
        case 'r': fi->align = 2; break;
        default: printf("Wrong alignment!\n");
    }
}
void toggle_bold(struct font_info * fi)
{
    fi->bold = !(fi->bold);
}
void toggle_italic(struct font_info * fi)
{
    fi->italic = !(fi->italic);
}
void toggle_underline(struct font_info * fi)
{
    fi->underline = !(fi->underline);
}
void show_menu(void)
{
    puts("f)change font    s)change size    a)change alignment");
    puts("b)toggle bold    i)toggle italic  u)toggle underline");
    puts("q)quit");
}
