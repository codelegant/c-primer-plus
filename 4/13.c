#include <stdio.h>
#define Q "His Hamlet was funny without being vulgar. "

int main(void)
{
  printf("%2.2f\n", 2.345e2);
  printf("%c%c%c\n", 'H', 105, '\41');
  printf("\"%s\" has %d characters.\n",Q, strlen(Q));
  printf("Is %2.2e the same as %2.2f?\n", 1201.0, 1201.0);
  return 0;
}