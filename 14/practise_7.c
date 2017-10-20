/* booksave.c -- saves structure contents in a file */
#include <stdio.h>
#include <stdlib.h>
#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   10             /* maximum number of books */

struct book {                   /* set up book template    */
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
};

int main(void)
{
  struct book library[MAXBKS]; /* array of structures     */
  int count = 0;
  int index, filecount;
  char action;
  FILE * pbooks;
  int size = sizeof (struct book);

  if ((pbooks = fopen("book.dat", "r+b")) == NULL)
  {
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
  filecount = count;

  puts("********************************************************************************");
  puts("Enter the character corresponding to the action:");
  puts("a) Append                              d) Delete");
  puts("m) Modify                              q) Quit");
  puts("********************************************************************************");

  while ( scanf("%c", &action) && action != 'q') {
    while (getchar() != '\n')
      continue;                /* clear input line  */

    if (action != 'a' && action != 'd' && action != 'm' ) {
      puts("The character should be a, d or m");
      puts("Enter the character corresponding to the action:");
      continue;
    }

    switch (action) {
      case 'a':
        if (count == MAXBKS)
        {
          fputs("The book.dat file is full.", stderr);
          exit(2);
        }

        puts("Please add new book titles.");
        puts("Press [enter] at the start of a line to stop.");
        while (
            count < MAXBKS &&
            gets(library[count].title) != 0 &&
            library[count].title[0] != '\0'
            ) {
          puts("Now enter the author.");
          gets(library[count].author);
          puts("Now enter the value.");
          scanf("%f", &library[count++].value);
          while (getchar() != '\n')
            continue;                /* clear input line  */
          if (count < MAXBKS)
            puts("Enter the next title.");
        }

        break;
      case 'd':
        printf("Enter the index of the book you want delete: ");
        int index;
        while (scanf("%d", &index) ) {
          if (index <= 0 && index > count + 1) {
            puts("The index is out of range.");
            printf("Enter the index of the book you want delete: ");
            continue;
          }

          break;
        }
        break;
    }
    fwrite(&library[filecount], size, count - filecount, pbooks);
    fclose(pbooks);
    puts("Enter the character corresponding to the action:");
  }


  if (count > 0) { 	
    puts("Here is the list of your books:");
    for (index = 0; index < count; index++)
      printf("%s by %s: $%.2f\n",library[index].title,
          library[index].author, library[index].value);
  } else {
    puts("No books? Too bad.\n");
  }

  puts("Bye.\n");

  return 0;
}
