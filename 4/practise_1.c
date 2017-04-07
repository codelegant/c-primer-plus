#include <stdio.h>

int main(void)
{
  char firstname[40];
  char lastname[40];
  printf("Please enter your fullname\n");
  scanf("%s %s",firstname,lastname);
  printf("Your fullname is: %s, %s\n",firstname,lastname);
  return 0;
}