#include <stdio.h>

int main(void)
{
  char ch;
  scanf("%c",&ch);
  while(ch != 'g')
  {
    printf("%c", ch);
    scanf("%c", &ch);
  }

  return 0;
}