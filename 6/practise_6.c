#include <stdio.h>

int main(void)
{
  char string[20];
  short i;
  printf("Enter a word: ");
  scanf("%s",&string);

  for(i=strlen(string)-1;i>=0;i--)
    printf("%c", string[i]);

  return 0;
}