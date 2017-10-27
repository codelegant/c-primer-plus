#include <stdio.h>

void ShowA(char *);
void ShowB(char *);

int main(void) {
  void  (*functions[10]) (char *);
  functions[0] = ShowA;
  functions[1] = ShowB;
  functions[0]("This is functions[0]");
  functions[1]("This is functions[1]");
  return 0;
}

void ShowA(char *str) {
  printf("%s\n", str);
}

void ShowB(char *str) {
  printf("%s\n", str);
}
