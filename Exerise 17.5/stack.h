/* stack.h -- header file for stack.c */
#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

#define MAXITEMS 100

typedef char Item;
typedef struct node {
    Item item;
    struct node * next;
} Node;

typedef struct stack {
    Node * top;
    int size;
} Stack;

/* operation:       initialize a stack
   preconditions:   pstack is a pointer to Stack
   postconditions:  pstack points to an empty stack         */
void InitializeStack(Stack * pstack);

/* operation:       check if the stack is empty
   preconditions:   pstack points to an initialized stack
   postconditions:  the function returns true if the
                    stack is empty or false otherwise       */
bool StackIsEmpty(const Stack * pstack);

/* operation:       check if the stack is full
   preconditions:   pstack points to an initialized stack
   postconditions:  the function returns true if the
                    stack is full or false otherwise        */
bool StackIsFull(const Stack * pstack);

/* operation:       push an item onto the stack
   preconditions:   pstack points to an initialized stack
                    pitem points to an Item
   postconditions:  if possible, the function pushes the
                    item onto the stack and returns true;
                    otherwise it returns false              */
bool PushStack(Stack * pstack, Item * pitem);

/* operation:       pop an item from the stack
   preconditions:   pstack points to an initialized stack
                    pitem points an Item
   postconditions:  if possible, the function removes the
                    top item from the stack and returns it
                    by the pointer provided, and then
                    returns true; otherwise it returns
                    false                                   */
bool PopStack(Stack * pstack, Item * pitem);

/* operation:       clears all the items on the stack
   preconditions:   pstack points to an initialized stack
   postconditions:  the stack becomes empty                 */
bool EmptyTheStack(Stack * pstack);

#endif // _STACK_H_
