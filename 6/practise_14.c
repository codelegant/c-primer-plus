#include <stdio.h>

int main(void)
{
  const short LENGTH=225;
  char sentence[LENGTH];
  short i=0;
  short scanfResult;

  printf("Enter a sentence: \n");
  do{
    scanf("%c", &sentence[i]);
  }while(sentence[i]!=10 && ++i<225);

  do{
    printf("%c", sentence[i]);
  }while(--i<strlen(sentence));

  return 0;
}
