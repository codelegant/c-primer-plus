/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* local function prototype */

/* interface functions   */
/* set the list to empty */
void InitializeList(List *plist)
{
  plist->items = 0;
}

/* returns true if list is empty */
bool ListIsEmpty(const List *plist)
{
  return plist->items == 0;
}

/* returns true if list is full */
bool ListIsFull(const List *plist)
{
  return plist->items == MAXSIZE;
}

/* returns number of nodes */
unsigned int ListItemCount(const List *plist)
{
  return plist->items;
}

/* creates node to hold item and adds it to the end of */
/* the list pointed to by plist (slow implementation)  */
bool AddItem(Item item, List *plist)
{
  plist->entries[plist->items] = item;
  plist->items = plist->items + 1;
  return true;
}

/* visit each node and execute function pointed to by pfun */
void Traverse(const List *plist, void (*pfun)(Item item))
{
  int index = 0;
  while (index < plist->items) {
    /* apply function to item */
    (*pfun)(plist->entries[index++]);
  }
}

/* free memory allocated by malloc() */
/* set list pointer to NULL          */
void EmptyTheList(List *plist)
{
  int length = plist->items;
  int index = 0;
  memset(plist->entries, 0, sizeof(plist->entries));
  plist->items = 0;
}

