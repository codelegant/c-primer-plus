#include <stdio.h>

int main(void)
{
  char name[40];
  float height;

  printf("Enter your name and height of in.\n");
  scanf("%s %f",name,&height);
  printf("%s, your are %.3f feet tall\n", name,height*.08);

  return 0;
}