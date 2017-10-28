#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LENGTH 40
#define ARRAY_LENGTH 5
struct Name {
  char firstname[NAME_LENGTH];
  char lastname[NAME_LENGTH];
};

void showarray(const struct Name ar[], int n);
int mycomp(const void * p1, const void * p2);

int main(void)
{
  struct Name names[ARRAY_LENGTH] = {
    {"Chuanfeng", "Lai"},
    {"Chaiyun", "Xiao"},
    {"Guiping", "Lai"},
    {"Chiulian", "Xiao"},
    {"Xunji", "Lai"}
  };

  puts("Random list:");
  showarray(names, ARRAY_LENGTH);
  qsort(names, ARRAY_LENGTH, sizeof(struct Name), mycomp);
  puts("\nSorted list:");
  showarray(names, ARRAY_LENGTH);
  return 0;
}

void showarray(const struct Name ar[], int n)
{
  int index;

  for(index = 0; index < n; index++)
  {
    printf(" %s %s,", ar[index].firstname, ar[index].lastname);
  }
  putchar('\n');
}

int mycomp(const void * p1, const void * p2)
{
  int result;
  struct Name *a1 = (struct Name *) p1; 
  struct Name *a2 = (struct Name *) p2;
  unsigned long size1 = 8 * (strlen(a1->firstname) + strlen(a1->lastname) + 1);
  unsigned long size2 = 8 * (strlen(a2->firstname) + strlen(a2->lastname) + 1);

  printf("Size1 %lu\n", size1);
  printf("Size2 %lu\n", size2);

  char *fullname1 = (char *) malloc(size1);
  char *fullname2 = (char *) malloc(size2);
  fullname1[0] = '\0';
  fullname2[0] = '\0';

  strcat(fullname1, a1->firstname);
  strcat(fullname1, a1->lastname);
  strcat(fullname2, a2->firstname);
  strcat(fullname2, a2->lastname);

  result = strcmp(fullname1, fullname2);

  free(fullname1);
  free(fullname2);

  return result > 0 ? 1 : result < 0 ? -1 : 0;
}
