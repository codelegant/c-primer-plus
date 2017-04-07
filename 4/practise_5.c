#include <stdio.h>

int main(void)
{
  char firstname[40];
  char lastname[40];

  printf("Your firstname\n");
  scanf("%s",firstname);
  printf("Your lastname\n");
  scanf("%s",lastname);

  printf("%s %s\n",firstname,lastname );
  printf("%*d %*d\n",strlen(firstname),strlen(firstname),strlen(lastname),strlen(lastname));

  printf("%s %s\n",firstname,lastname );
  printf("%-*d %-*d\n",strlen(firstname),strlen(firstname),strlen(lastname),strlen(lastname));

  return 0;
}