#include <stdio.h>
#define ADJUST 7.64F
#define SCALE 0.325F

int main(void)
{
  float shoe;
  float foot;

  printf("Shoe size(men's) foot length\n");
  shoe=3.0;
  while(shoe<18.5)
  {
    foot=SCALE*shoe+ADJUST;
    printf("%10.1f %15.2f inches\n", shoe, foot);
    shoe=shoe+0.1;
  }

  printf("If the shoe fits, wear it.\n");
  return 0;
}