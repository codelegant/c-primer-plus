#include <stdio.h>

int main(void)
{
  short letter;
  short index;
  char letters[26];

  for(letter='a',index=0; index<26; letter++,index++)
    letters[index]=letter;

  for(index=0; index<26; index++)
    printf("%c ",letters[index]);

  return 0;
}