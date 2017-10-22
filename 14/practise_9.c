#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAXNAME 40
#define MAXSEATS 12
#define STARS "****************************************"
const int flights[4] = {102, 311, 444, 519};

struct seat {
  int flight;
  int number;
  bool assignable;
  bool confirmed;
  char firstname[MAXNAME];
  char lastname[MAXNAME];
};

char * GetFilename(int flight);
void LoadAndInitFile(int flight, struct seat airplane[]);
int ChooseFlight(void);
char OperateFlight(int flight);
void ShowNumber(const struct seat airplane[], int length);
void ShowList(const struct seat airplane[], int length);
void ShowAlphabeticalList(const struct seat airplane[], int length);
void AssignSeat(struct seat airplane[], int length, int flight);
void ConfirmAssignSeat(struct seat airplane[], int length, int flight);
void DeleteSeat(struct seat airplane[], int length, int flight);
void IgnoreChar(void);
void SaveToFile(struct seat airplane[], int length, int flight);

int main(void) {
  struct seat airplane[MAXSEATS];
  char action;
  int flight_code;
  while ((flight_code = ChooseFlight()) != 5) {
    int flight = flights[flight_code-1];
    printf("You has choose a flight %d.\n", flight);
    LoadAndInitFile(flight, airplane);
    while ((action = OperateFlight(flight)) != 'g') {
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
          AssignSeat(airplane, MAXSEATS, flight);
          break;
        case 'e':
          ConfirmAssignSeat(airplane, MAXSEATS, flight);
          break;
        case 'f':
          DeleteSeat(airplane, MAXSEATS, flight);
          break;
        default:
          puts("Enter an character from a to g, please.");
          continue;
      }
    }

  }
  return 0;
}

char * GetFilename(int flight) {
  char flight_name[3];
  char filename[14] = "flight_";
  char *p_filename = "flight_";
  sprintf(flight_name, "%d", flight);
  strcat(filename, flight_name);
  strcat(filename, ".dat");
  p_filename = filename;
  return p_filename;
}

void LoadAndInitFile(int flight, struct seat airplane[]) {
  int index;
  int count;
  FILE *p_seat;
  const int size = sizeof (struct seat);
  const char *filename = GetFilename(flight);
  printf("LoadAndInitFile Filename is %s\n", filename);

  if ((p_seat = fopen(filename, "a+b")) == NULL) {
  printf("LoadAndInitFile error Filename is %s\n", filename);
    fprintf(stderr, "Can't open %s file in a+b mode.\n", filename);
    exit(EXIT_FAILURE);
  }

  rewind(p_seat);            /* go to start of file     */
  while (count < MAXSEATS && fread(&airplane[count], size, 1, p_seat) == 1) {
    const struct seat current_seat = airplane[count];
    if (count == 0)
      puts("The assigned seats:");

    if (!current_seat.assignable)
      printf(
          "Seat flight: %d, number: %d, customer name: %s %s.\n",
          current_seat.flight,
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
    airplane[index].flight = flight;
    airplane[index].number = index+1;
    airplane[index].assignable = true;
    airplane[index].confirmed = false;
    ++index;
  }
}

int ChooseFlight(void) {
  int code;
  printf("\n%s%s\n", STARS, STARS);
  puts("To choose a flight, enter its number label:");
  printf("1) Flight %d\n", flights[0]);
  printf("2) Flight %d\n", flights[1]);
  printf("3) Flight %d\n", flights[2]);
  printf("4) Flight %d\n", flights[3]);
  puts("5) Quit");
  printf("%s%s\n", STARS, STARS);
  while (scanf("%d", &code) != 1 ||
      (code < 1|| code > 5)) {
    puts("Enter an character from 1 to 5, please.");
  }
  IgnoreChar();
  return code;
}

char OperateFlight(int flight) {
  char action;
  printf("\n%s%s\n", STARS, STARS);
  printf("Current flight is %d, To choose a action, enter its letter label:\n",
      flight);
  puts("a) Show number of empty seats");
  puts("b) Show list of empty seats");
  puts("c) Show alphabetical list of seats");
  puts("d) Assign a customer to a seat assignments");
  puts("e) Confirm a seat assignments");
  puts("f) Delete a seat assignment");
  puts("g) Go to choose flight");
  printf("%s%s\n", STARS, STARS);
  while (scanf("%c", &action) != 1 ||
      (action < 'a' || action > 'g')) {
    puts("Enter an character from a to g, please.");
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
    const struct seat current_seat = airplane[index++];
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
    const struct seat *current_seat = temp_airplane[index++];
    if (!current_seat->assignable)
      printf(
          "Seat info: flight is %d, number is %d, customer name is %s %s, confirm status: %s\n", 
          current_seat->flight,
          current_seat->number,
          current_seat->firstname,
          current_seat->lastname,
          current_seat->confirmed ? "true" : "false"
          );
  }
}

void AssignSeat(struct seat airplane[], int length, int flight) {
  int index;
  const char tip[] = "Enter the number of the seat you want assign, press [0] to end: ";
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
      airplane[index-1].flight = flight;
      airplane[index-1].number = index;
      airplane[index-1].assignable = false;

      const struct seat current_seat = airplane[index-1];
      printf("The seat you assigned: flight is %d, number is %d, customer name is %s %s\n", 
          current_seat.flight,
          current_seat.number,
          current_seat.firstname,
          current_seat.lastname);
      break;
    }
    printf("%s", tip);
  }

  IgnoreChar();
  SaveToFile(airplane, length, flight);
}

void ConfirmAssignSeat(struct seat airplane[], int length, int flight) {
  int index;
  const char tip[] = "Enter the number of the seat you want confirm, press [0] to end: ";
  printf("%s", tip);

  while (scanf("%d", &index)) {
    if (!index) 
      break;

    if (index <= 0 && index > length) {
      puts("Enter an integer from 1 to 12, please.");
      printf("%s", tip);
      continue;
    }
      const struct seat current_seat = airplane[index-1];
      if (current_seat.confirmed) {
      printf("The seat which number is %d already confirmed.\n",
          current_seat.number);
      } else {
      printf("The seat you confirmed: flight is %d, number is %d, customer name is %s %s\n", 
          current_seat.flight,
          current_seat.number,
          current_seat.firstname,
          current_seat.lastname);
      airplane[index-1].confirmed = true;
      }
    printf("%s", tip);
  }

  IgnoreChar();
  SaveToFile(airplane, length, flight);
}

void DeleteSeat(struct seat airplane[], int length, int flight) {
  int index;
  const char tip[] = "Enter the number of the seat you want delete, press [0] to end: ";
  printf("%s", tip);

  while (scanf("%d", &index)) {
    if (!index) 
      break;

    if (index <= 0 && index > length) {
      puts("Enter an integer from 1 to 12, please.");
      printf("%s", tip);
      continue;
    }

    const struct seat current_seat = airplane[index-1];
    if (current_seat.assignable) {
      printf("The seat which number is %d already deleted.\n",
          current_seat.number);
    } else {
      printf("The seat you deleted: flight is %d, number is %d, customer name is %s %s\n", 
          current_seat.flight,
          current_seat.number,
          current_seat.firstname,
          current_seat.lastname);

      airplane[index-1].assignable = true;
      airplane[index-1].assignable = false;
      airplane[index-1].firstname[0] = '\0';
      airplane[index-1].lastname[0] = '\0';
    }
    printf("%s", tip);
  }

  IgnoreChar();
  SaveToFile(airplane, length, flight);
}

void IgnoreChar(void) {
  while (getchar() != '\n')
    continue;
}

void SaveToFile(struct seat airplane[], int length, int flight) {
  FILE *p_seat;
  const int size = sizeof (struct seat);
  const char *filename = GetFilename(flight);
  if ((p_seat = fopen(filename, "w+b")) == NULL) {
    fprintf(stderr, "Can't open %s file in w+b mode.\n", filename);
    exit(EXIT_FAILURE);
  }
  rewind(p_seat);
  fwrite(airplane, size, length, p_seat);
  fclose(p_seat);
}
