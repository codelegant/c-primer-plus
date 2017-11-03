/* stack.h -- interface for a stack */
#ifndef _stack_H_
#define _stack_H_
#include <stdbool.h>
#define MAXSTACK 100

typedef char Item;
typedef struct node
{
    Item item;
    struct node * next;
} Node;
typedef struct stack
{
    Node * front;  /* pointer to front of stack  */
    Node * rear;   /* pointer to rear of stack   */
    int items;     /* number of items in stack   */
} Stack;

/* operation:        initialize the stack                       */
/* precondition:     ps points to a stack                       */
/* postcondition:    stack is initialized to being empty        */
void InitializeStack(Stack * ps);

/* operation:        check if stack is full                     */
/* precondition:     ps points to previously initialized stack  */
/* postcondition:   returns True if stack is full, else False  */
bool StackIsFull(const Stack * ps);

/* operation:        check if stack is empty                    */
/* precondition:     ps points to previously initialized stack  */
/* postcondition:    returns True if stack is empty, else False */
bool StackIsEmpty(const Stack *ps);

/* operation:        determine number of items in stack         */
/* precondition:     ps points to previously initialized stack  */
/* postcondition:    returns number of items in stack           */
int StackItemCount(const Stack * ps);

/* operation:        add item to head of stack                  */
/* precondition:     ps points to previously initialized stack */
/*                   item is to be placed at rear of stack      */
/* postcondition:    if stack is not empty, item is placed at   */
/*                   rear of stack and function returns         */
/*                   True; otherwise, stack is unchanged and    */
/*                   function returns False                     */
bool EnStack(Item item, Stack * ps);

/* operation:        remove item from head of stack            */
/* precondition:     ps points to previously initialized stack  */
/* postcondition:    if stack is not empty, item at head of     */
/*                   stack is copied to *pitem and deleted from */
/*                   stack, and function returns True; if the   */
/*                   operation empties the stack, the stack is  */
/*                   reset to empty. If the stack is empty to   */
/*                   begin with, stack is unchanged and the     */
/*                   function returns False                     */
bool DeStack(Item *pitem, Stack * ps);

/* operation:        empty the stack                            */
/* precondition:     ps points to previously initialized stack  */
/* postconditions:   the stack is empty                         */
void EmptyTheStack(Stack * ps);

#endif
