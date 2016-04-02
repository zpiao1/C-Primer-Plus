/* reverseString.c -- an implementation of the stack */
#include <stdio.h>
#include "stack.h"

int main(void)
{
    Stack string;
    Item ch;

    puts("Enter the string, end with a newline:");
    InitializeStack(&string);
    while ((ch = getchar()) != '\n')
    {
        if (StackIsFull(&string))
        {
            fprintf(stderr, "The stack is full already\n");
            break;
        }
        PushStack(&string, &ch);
    }
    puts("The reverse order:");
    while (!(StackIsEmpty(&string)))
    {
        PopStack(&string, &ch);
        DisplayItem(ch);
    }
    puts("\nThank you!");

    return 0;
}
