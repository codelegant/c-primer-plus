/* stack.c -- the Stack type implementation*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* local functions */
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);

void InitializeStack(Stack * ps) {
    ps->front = ps->rear = NULL;
    ps->items = 0;
}

bool StackIsFull(const Stack * ps) {
    return ps->items == MAXSTACK;
}

bool StackIsEmpty(const Stack * ps) {
    return ps->items == 0;
}

int StackItemCount(const Stack * ps) {
    return ps->items;
}

bool EnStack(Item item, Stack * ps) {
    Node * pnew;

    if (StackIsFull(ps))
        return false;
    pnew = (Node *) malloc( sizeof(Node));
    if (pnew == NULL) {
        fprintf(stderr,"Unable to allocate memory!\n");
        exit(1);
    }
    CopyToNode(item, pnew);
    pnew->next = ps->front;
    if (StackIsEmpty(ps))
        ps->rear = pnew;           /* item goes to front     */
    ps->front = pnew;                /* record location of end */
    ps->items++;                    /* one more item in stack */
   
    return true;
}

bool DeStack(Item * pitem, Stack * ps) {
    Node * pt;

    if (StackIsEmpty(ps))
        return false;
    CopyToItem(ps->front, pitem);
    pt = ps->front;
    ps->front = ps->front->next;
    free(pt);
    ps->items--;
    if (ps->items == 0)
        ps->rear = NULL;
 
    return true;
}

/* empty the stack                */
void EmptyTheStack(Stack * ps) {
    Item dummy;
    while (!StackIsEmpty(ps))
        DeStack(&dummy, ps);
}

/* Local functions                 */

static void CopyToNode(Item item, Node * pn) {
    pn->item = item;
}

static void CopyToItem(Node * pn, Item * pi) {
    *pi = pn->item;
}
