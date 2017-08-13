#include <stdio.h>
#include <string.h>
typedef struct lens{
  float foclen;
  float fstop;
  char brand[30];
} LENS;

int main(void) {
  LENS lens[10] = { [2]={ 500, 2.0, "Remarkatar" } };
  lens[1]=(LENS){400, 1.8, "Canon"};
  strcpy(lens[0].brand , "Nikon");
  printf("%.2f\n", lens[1].foclen);
  return 0;
}
