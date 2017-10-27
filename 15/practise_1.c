#include <stdio.h>
#include <math.h>
#include <string.h>

int StrToInt(char *);

int main(void) {
  char *p_bin = "01001001";
  int number = StrToInt(p_bin);
  printf("The DEC is %d\n", number);
  return 0;
}

int StrToInt(char *p_bin) {
  int count = 0;
  int index = 0;
  int length = strlen(p_bin);
  while (length) 
    count += (p_bin[--length] - 48) * pow(2, index++);

  return count;
}
