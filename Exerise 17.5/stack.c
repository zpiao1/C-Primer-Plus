#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void DisplayItem(Item item);
/* local function prototype */
static Node * NewNode(const Item * pitem);

/* Interface function definitions */
void InitializeStack(Stack * pstack)
{
    pstack->size = 0;
    pstack->top = NULL;
}

bool StackIsEmpty(const Stack * pstack)
{
    return (pstack->size == 0);
}

bool StackIsFull(const Stack * pstack)
{
    return (pstack->size == MAXITEMS);
}

bool PushStack(Stack * pstack, Item * pitem)
{
    Node * new_node;

    if (StackIsFull(pstack))
    {
        fprintf(stderr, "The stack is full, cannot push\n");
        return false;
    }

    new_node = NewNode(pitem);
    new_node->next = pstack->top;
    pstack->top = new_node;
    pstack->size++;
    return true;
}

bool PopStack(Stack * pstack, Item * pitem)
{
    Node * temp;

    if (StackIsEmpty(pstack))
    {
        fprintf(stderr, "The stack is empty, cannot pop\n");
        return false;
    }

    *pitem = pstack->top->item;
    pstack->size--;
    temp = pstack->top;
    pstack->top = pstack->top->next;
    free(temp);
    return true;
}

bool EmptyTheStack(Stack * pstack)
{
    Item * temp = NULL;

    if (StackIsEmpty(pstack))
    {
        fprintf(stderr, "The stack is empty, no need to clean\n");
        return false;
    }

    while (!StackIsEmpty(pstack))
        PopStack(pstack, temp);
    return true;
}

void DisplayItem(Item item)
{
    putchar(item);
}

/* local function definitions */
static Node * NewNode(const Item * pitem)
{
    Node * new_node = (Node *) malloc(sizeof(Node));
    new_node->item = *pitem;
    return new_node;
}
