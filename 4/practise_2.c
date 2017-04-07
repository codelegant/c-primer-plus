#include <stdio.h>

int main(void)
{
  char lastname[40];

  printf("Enter your lastname\n");
  scanf("%s", lastname);
  printf("Lastname: \"%s\"\n", lastname);
  printf("Lastname: \"%20s\"\n", lastname);
  printf("Lastname: \"%-20s\"\n", lastname);
  printf("Lastname: \"%*s\"\n",strlen(lastname)+3, lastname);

  return 0;
}