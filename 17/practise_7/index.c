#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void PrintWord(Node node);

int main(void) {
  FILE *fp;
  Tree dialog;
  Item word;
  
  if ((fp = fopen("dialog.txt", "r")) == NULL) {
    fprintf(stderr, "Cant't open \"dialog.txt\" file.\n");
    exit(EXIT_FAILURE);
  }
  InitializeTree(&dialog);
  while (fscanf(fp, "%s", word) == 1) {
    AddItem(&word, &dialog);
  }
  Traverse(&dialog, PrintWord);
  putchar('\n');
  fclose(fp);

  return 0;
}

void PrintWord(Node node) {
  printf("%s->%d\n", node.item, node.count);
}
