#include <stdio.h>

void praise(void);
void summary(void);

int main(void)
{
  praise();
  summary();
  return 0;
}

void praise(void)
{
  printf("For he's a jolly good fellow!\n");
  printf("For he's a jolly good fellow!\n");
  printf("For he's a jolly good fellow!\n");
}

void summary(void)
{
  printf("Which nobody can deny!\n");
}