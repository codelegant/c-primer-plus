#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAXNAME 40
#define MAXSEATS 12
#define STARS "****************************************"

struct seat {
  int number;
  bool assignable;
  char firstname[MAXNAME];
  char lastname[MAXNAME];
};

char ChooseAction(void);
void ShowNumber(const struct seat [], int);
void ShowList(const struct seat [], int);
void ShowAlphabeticalList(const struct seat [], int);
void AssignSeat(struct seat [], int);
void DeleteSeat(struct seat [], int);
void IgnoreChar(void);
void SaveToFile(struct seat [], int);

int main(void) {
  struct seat airplane[MAXSEATS]; /* array of structures     */
  int count = 0;
  int index = 0;
  char action;
  FILE *p_seat;
  int size = sizeof (struct seat);

  if ((p_seat = fopen("airplane.dat", "a+b")) == NULL) {
    fputs("Can't open airplane.dat file in a+b mode.\n", stderr);
    exit(EXIT_FAILURE);
  }

  rewind(p_seat);            /* go to start of file     */
  while (count < MAXSEATS && fread(&airplane[count], size, 1, p_seat) == 1) {
    struct seat current_seat = airplane[count];
    if (count == 0)
      puts("The assigned seats:");

    if (!current_seat.assignable)
      printf(
          "Seat number: %d, customer name: %s %s.\n",
          current_seat.number,
          current_seat.firstname,
          current_seat.lastname
          );
    ++count;
  }
  index = count;
  fclose(p_seat);

  // 初始化数据，如果数据不满 12 个，用默认数据填充
  while (index < MAXSEATS) {
    airplane[index].number = index+1;
    airplane[index].assignable = true;
    ++index;
  }

  while ((action = ChooseAction()) != 'f') {
    switch (action) {
      case 'a':
        ShowNumber(airplane, MAXSEATS);
        break;
      case 'b':
        ShowList(airplane, MAXSEATS);
        break;
      case 'c':
        ShowAlphabeticalList(airplane, MAXSEATS);
        break;
      case 'd':
        AssignSeat(airplane, MAXSEATS);
        break;
      case 'e':
        DeleteSeat(airplane, MAXSEATS);
        break;
      default:
        puts("Enter an character from a to f, please.");
        continue;
    }
  }
  return 0;
}

char ChooseAction(void) {
  char action;
  printf("\n%s%s\n", STARS, STARS);
  puts("To choose a action, enter its letter label:");
  puts("a) Show number of empty seats");
  puts("b) Show list of empty seats");
  puts("c) Show alphabetical list of seats");
  puts("d) Assign a customer to a seat assignments");
  puts("e) Delete a seat assignment");
  puts("f) Quit");
  printf("%s%s\n", STARS, STARS);
  while (scanf("%c", &action) != 1 ||
      (action < 'a' || action > 'f')) {
    puts("Enter an character from a to f, please.");
  }
  IgnoreChar();
  return action;
}

void ShowNumber(const struct seat airplane[], int length) {
  int count = 0;
  int index = 0;
  while (index < length) {
    if (airplane[index++].assignable)
      ++count;
  }
  printf("The number of empty seats is %d\n", count);
}

void ShowList(const struct seat airplane[], int length) {
  int index = 0;
  puts("The list of empty seats:");
  while (index < length) {
    struct seat current_seat = airplane[index++];
    if(current_seat.assignable)
      printf("Number is %d\n", current_seat.number);
  }
}

void ShowAlphabeticalList(const struct seat airplane[], int length) {
  struct seat *temp_airplane[MAXSEATS];
  struct seat *temp;
  int index = 0;
  int top;
  int seek;

  while (index < length) {
    temp_airplane[index] = &airplane[index];
    ++index;
  }

  for (top = 0; top < length-1; ++top) {
    for (seek = top+1; seek < length; ++seek) {
      if (strcmp(temp_airplane[top]->firstname, temp_airplane[seek]->firstname) > 0) {
        temp = temp_airplane[top];
        temp_airplane[top] = temp_airplane[seek];
        temp_airplane[seek] = temp;
      }
    }
  }

  index = 0;
  puts("Show alphabetical list of seats:");
  while (index < length) {
    struct seat *current_seat = temp_airplane[index++];
    if (!current_seat->assignable)
      printf("Seat info: number is %d, customer name is %s %s\n", 
          current_seat->number,
          current_seat->firstname,
          current_seat->lastname);
  }
}

void AssignSeat(struct seat airplane[], int length) {
  int index;
  char tip[] = "Enter the number of the seat you want assign, press [0] to end: ";
  printf("%s", tip);

  while (scanf("%d", &index)) {
    if (!index) 
      break;

    if (index <= 0 && index > length) {
      puts("Enter an integer from 1 to 12, please.");
      printf("%s", tip);
      continue;
    }

    printf("Please the firstname of customer: ");
    IgnoreChar();
    while (scanf("%s", airplane[index-1].firstname) != 0 && 
        airplane[index-1].firstname[0] != '\0') {
      IgnoreChar();
      printf("Now enter the lastname: ");
      scanf("%s", airplane[index-1].lastname);
      IgnoreChar();
      airplane[index-1].assignable = false;
      airplane[index-1].number = index;

      struct seat current_seat = airplane[index-1];
      printf("The seat you assigned: number is %d, customer name is %s %s\n", 
          current_seat.number,
          current_seat.firstname,
          current_seat.lastname);
      break;
    }
    printf("%s", tip);
  }

  IgnoreChar();
  SaveToFile(airplane, length);
}

void DeleteSeat(struct seat airplane[], int length) {
  int index;
  char tip[] = "Enter the number of the seat you want delete, press [0] to end: ";
  printf("%s", tip);

  while (scanf("%d", &index)) {
    if (!index) 
      break;

    if (index <= 0 && index > length) {
      puts("Enter an integer from 1 to 12, please.");
      printf("%s", tip);
      continue;
    }

    struct seat current_seat = airplane[index-1];
    if (current_seat.assignable) {
      printf("The seat which number is %d no need to delete.\n",
          current_seat.number);
    } else {
      printf("The seat you deleted: number is %d, customer name is %s %s\n", 
          current_seat.number,
          current_seat.firstname,
          current_seat.lastname);

      airplane[index-1].assignable = true;
      airplane[index-1].firstname[0] = '\0';
      airplane[index-1].lastname[0] = '\0';
    }
    printf("%s", tip);
  }

  IgnoreChar();
  SaveToFile(airplane, length);
}

void IgnoreChar(void) {
  while (getchar() != '\n')
    continue;
}

void SaveToFile(struct seat airplane[], int length) {
  FILE *p_seat;
  int size = sizeof (struct seat);
  if ((p_seat = fopen("airplane.dat", "w+b")) == NULL) {
    fputs("Can't open airplane.dat file in w+b mode.\n", stderr);
    exit(EXIT_FAILURE);
  }
  rewind(p_seat);
  fwrite(airplane, size, length, p_seat);
  fclose(p_seat);
}
