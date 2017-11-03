#include <stdio.h>
#include "stack.h"

int main(void) {
  char items[MAXSTACK];
  int index = 0;
  Stack chs;
  Item ch;

  InitializeStack(&chs);
  puts("Enter a string, in 100 characters.");
  gets(items);

  while ((ch = items[index]) != '\0') {
    EnStack(ch, &chs);
    index++;
  }

  while (!StackIsEmpty(&chs)) {
    DeStack(&ch, &chs);
    putchar(ch);
  }
  putchar('\n');
  EmptyTheStack(&chs);
  return 0;
}
