#include <stdio.h>
#define PRAISE "What a super marvelous name!";

int main(void)
{
  char name[40];

  printf("What's your name?\n");
  scanf("%s",name);
  printf("Hello, %s. %s\n", name,PRAISE);
  system("PAUSE");
  return 0;
}