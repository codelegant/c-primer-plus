#include <stdio.h>

int main(void)
{

  char c16 ='\x41';
  char c8='\101';

  int i16=0x41;
  int i8=0101;
  int i10=65;

  unsigned u16=0x41u;
  unsigned u8=0101u;
  unsigned u10=65u;

  printf("c16 %c, c8 %c\n",c16,c8);
  printf("i16 %c, i8 %c, i10 %c \12",i16,i8,i10);
  printf("u16 %c, u8 %c, u10 %c \n",u16,u8,u10);

  return 0;

}