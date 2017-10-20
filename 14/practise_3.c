/* manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>
#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   100              /* maximum number of books  */

struct book {                     /* set up book template */
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
};
void OrderByTitle(struct book [], int);
void OrderByValue(struct book [], int);
void ShowInfo(struct book [], int, const char *);

int main(void)
{
  struct book library[MAXBKS]; /* array of book structures */
  int count = 0;

  printf("Please enter the book title.\n");
  printf("Press [enter] at the start of a line to stop.\n");
  while (count < MAXBKS &&
      gets(library[count].title) != 0 && library[count].title[0] != '\0') {
    printf("Now enter the author.\n");
    gets(library[count].author);
    printf("Now enter the value.\n");
    scanf("%f", &library[count++].value);
    while (getchar() != '\n')
      continue;          /* clear input line */
    if (count < MAXBKS)
      printf("Enter the next title.\n");
  }

  ShowInfo(library, count, "enter");
  OrderByTitle(library, count);
  ShowInfo(library, count, "title");
  OrderByValue(library, count);
  ShowInfo(library, count, "value");

  return 0;
}

void OrderByTitle(struct book library[], int count) {
  struct book temp;
  for (int top = 0; top < count-1; top++) {
    for (int seek = top+1; seek<count; seek++) {
      if (strcmp(library[top].title, library[seek].title) > 0) {
        temp = library[top];
        library[top] = library[seek];
        library[seek] = temp;
      }
    }
  }
}

void OrderByValue(struct book library[], int count) {
  struct book temp;
  for (int top = 0; top < count-1; top++) {
    for (int seek = top+1; seek<count; seek++) {
      if (library[top].value > library[seek].value) {
        temp = library[top];
        library[top] = library[seek];
        library[seek] = temp;
      }
    }
  }
}

void ShowInfo(struct book library[], int count, const char *ptr) {
  if (count > 0) {
    printf("Here is the list of your books order by %s:\n", ptr);
    for (int index = 0; index < count; index++)
      printf("%s by %s: $%.2f\n",
          library[index].title, library[index].author, library[index].value);
  } else {
    printf("No books? Too bad.\n");
  }
}
