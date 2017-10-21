/* booksave.c -- saves structure contents in a file */
#include <stdio.h>
#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   100             /* maximum number of books */

struct book {                   /* set up book template    */
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
};

void IgnoreChar(void);

int main(void)
{
  struct book library[MAXBKS]; /* array of structures     */
  int count = 0;
  char action;
  FILE * pbooks;
  int size = sizeof (struct book);

  if ((pbooks = fopen("book.dat", "a+b")) == NULL) {
    fputs("Can't open book.dat file\n",stderr);
    exit(1);
  }

  rewind(pbooks);            /* go to start of file     */
  while (count < MAXBKS &&  fread(&library[count], size, 1, pbooks) == 1) {
    if (count == 0)
      puts("Current contents of book.dat:");
    printf("Index: %d, ", count + 1);
    printf(
        "%s by %s: $%.2f\n",
        library[count].title,
        library[count].author,
        library[count].value
        );
    count++;
  }
  fclose(pbooks);

  puts("********************************************************************************");
  puts("Enter the character corresponding to the action:");
  puts("a) Append                              d) Delete");
  puts("m) Modify                              q) Quit");
  puts("********************************************************************************");

  while (scanf("%c", &action) && action != 'q') {
    int index;
    IgnoreChar();
    switch (action) {
      case 'a': // Append
        if (count == MAXBKS)
        {
          fputs("The book.dat file is full.\n", stderr);
          exit(2);
        }

        puts("Please add new book titles.");
        puts("Press [enter] at the start of a line to stop.");
        while (count < MAXBKS &&
            gets(library[count].title) != 0 &&
            library[count].title[0] != '\0') {
          puts("Now enter the author.");
          gets(library[count].author);
          puts("Now enter the value.");
          scanf("%f", &library[count++].value);
          IgnoreChar();
          if (count < MAXBKS)
            puts("Enter the next title.");
        }
        break;
      case 'd': // Delete
        printf("Enter the index of the book you want delete: ");
        while (scanf("%d", &index)) {
          IgnoreChar();
          if (index <= 0 && index > count+1) {
            puts("The index is out of range.");
            printf("Enter the index of the book you want delete: ");
            continue;
          }
          for (int i = index-1; i < count-1; i++) {
            library[i] = library[i+1];
          }
          count -= 1;
          break;
        }
        break;
      case 'm': // Modify
        printf("Enter the index of the book you want modify: ");
        while (scanf("%d", &index)) {
          IgnoreChar();
          if (index <= 0 && index > count+1) {
            puts("The index is out of range.");
            printf("Enter the index of the book you want modify: ");
            continue;
          }

          puts("Please add new book titles.");
          while (gets(library[index-1].title) != 0 && 
              library[index-1].title[0] != '\0') {
            puts("Now enter the author.");
            gets(library[index-1].author);
            puts("Now enter the value.");
            scanf("%f", &library[index-1].value);
            IgnoreChar();
            break;
          }
          break;
        }
        break;
      default:
        puts("The character should be a, d or m");
        printf("Enter the character corresponding to the action: ");
        continue;
    }
    printf("Enter the character corresponding to the action: ");
  }

  if ((pbooks = fopen("book.dat", "w+b")) == NULL) {
    fputs("Can't open book.dat file as w+b\n",stderr);
    exit(1);
  }
  rewind(pbooks);
  fwrite(library, size, count, pbooks);
  fclose(pbooks);


  if (count > 0) { 	
    puts("Here is the list of your books:");
    for (int index = 0; index < count; index++) {
      printf("Index: %d, ", index + 1);
      printf(
          "%s by %s: $%.2f\n",
          library[index].title,
          library[index].author, 
          library[index].value
          );
    }
  } else {
    puts("No books? Too bad.\n");
  }
  puts("Bye.\n");

  return 0;
}

void IgnoreChar(void) {
  while (getchar() != '\n')
    continue;
}
