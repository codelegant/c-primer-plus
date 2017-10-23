#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAXNAME 40
#define MAXSEATS 12
#define STARS "****************************************"
char *p_filename = NULL;
const int kFlights[4] = {102, 311, 444, 519};

struct Seat {
  int flight;
  int number;
  bool assignable;
  bool confirmed;
  char firstname[MAXNAME];
  char lastname[MAXNAME];
};

void GetFilename(int flight);
void LoadAndInitFile(int flight, struct Seat airplane[]);
int ChooseFlight(void);
char OperateFlight(int flight);
void ShowNumber(const struct Seat airplane[], int length);
void ShowList(const struct Seat airplane[], int length);
void ShowAlphabeticalList(const struct Seat airplane[], int length);
void AssignSeat(struct Seat airplane[], int length, int flight);
void ConfirmAssignSeat(struct Seat airplane[], int length, int flight);
void DeleteSeat(struct Seat airplane[], int length, int flight);
void IgnoreChar(void);
void SaveToFile(struct Seat airplane[], int length, int flight);

int main(void) {
  struct Seat airplane[MAXSEATS];
  char action;
  int flight_code;
  while ((flight_code = ChooseFlight()) != 5) {
    int flight = kFlights[flight_code-1];
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

void GetFilename(int flight) {
  const int kFlightNameLength = snprintf(NULL, 0, "%d", flight);
  const int kFilenameLength = 16;
  const char * const kPostfix = ".dat";
  char *p_flight_name = (char *)malloc(kFlightNameLength + 1);
  char filename[kFilenameLength] = "flight_";

  p_filename = (char *)malloc(kFilenameLength * sizeof (char));
  snprintf(p_flight_name, kFlightNameLength + 1, "%d", flight);
  strncat(filename, p_flight_name, strlen(p_flight_name));
  strncat(filename, kPostfix, strlen(kPostfix));

  if (p_filename != NULL)
    p_filename = filename;

  printf("GetFilename p_filename address %p\n", p_filename);
  printf("GetFilename p_filename is %s***\n", p_filename);
  if(!strcmp(p_filename, "flight_102.dat"))
    printf("GetFilename p_filename is equal.\n");
  printf("\n%s\n", STARS);
}

void LoadAndInitFile(int flight, struct Seat airplane[]) {
  int count = 0;
  int index;
  FILE *p_seat;
  const int kSize = sizeof (struct Seat);
  GetFilename(flight);

  printf("LoadAndInitFile p_filename address %p\n", p_filename);
  printf("LoadAndInitFile p_filename is %s***\n", p_filename);

  if(!strcmp(p_filename, "flight_102.dat"))
    printf("LoadAndInitFile p_filename is equal.\n");
  printf("\n%s\n", STARS);

  if ((p_seat = fopen(p_filename, "a+b")) == NULL) {
    fprintf(stderr, "Can't open %s file in a+b mode.\n", p_filename);
    exit(EXIT_FAILURE);
  }
  p_filename = NULL;

  rewind(p_seat);
  while (count < MAXSEATS && fread(&airplane[count], kSize, 1, p_seat) == 1) {
    const struct Seat kCurrentSeat = airplane[count];
    if (count == 0)
      puts("The assigned seats:");

    if (!kCurrentSeat.assignable)
      printf(
          "Seat flight: %d, number: %d, customer name: %s %s.\n",
          kCurrentSeat.flight,
          kCurrentSeat.number,
          kCurrentSeat.firstname,
          kCurrentSeat.lastname
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
  printf("1) Flight %d\n", kFlights[0]);
  printf("2) Flight %d\n", kFlights[1]);
  printf("3) Flight %d\n", kFlights[2]);
  printf("4) Flight %d\n", kFlights[3]);
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

void ShowNumber(const struct Seat airplane[], int length) {
  int count = 0;
  int index = 0;
  while (index < length) {
    if (airplane[index++].assignable)
      ++count;
  }
  printf("The number of empty seats is %d\n", count);
}

void ShowList(const struct Seat airplane[], int length) {
  int index = 0;
  puts("The list of empty seats:");
  while (index < length) {
    const struct Seat kCurrentSeat = airplane[index++];
    if(kCurrentSeat.assignable)
      printf("Number is %d\n", kCurrentSeat.number);
  }
}

void ShowAlphabeticalList(const struct Seat airplane[], int length) {
  struct Seat *temp_airplane[MAXSEATS];
  struct Seat *temp;
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
    const struct Seat *kCurrentSeat = temp_airplane[index++];
    if (!kCurrentSeat->assignable)
      printf(
          "Seat info: flight is %d, number is %d, customer name is %s %s, confirm status: %s\n", 
          kCurrentSeat->flight,
          kCurrentSeat->number,
          kCurrentSeat->firstname,
          kCurrentSeat->lastname,
          kCurrentSeat->confirmed ? "true" : "false"
          );
  }
}

void AssignSeat(struct Seat airplane[], int length, int flight) {
  int index;
  const char kTip[] = "Enter the number of the seat you want assign, press [0] to end: ";
  printf("%s", kTip);

  while (scanf("%d", &index)) {
    if (!index) 
      break;

    if (index <= 0 && index > length) {
      puts("Enter an integer from 1 to 12, please.");
      printf("%s", kTip);
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

      const struct Seat kCurrentSeat = airplane[index-1];
      printf("The seat you assigned: flight is %d, number is %d, customer name is %s %s\n", 
          kCurrentSeat.flight,
          kCurrentSeat.number,
          kCurrentSeat.firstname,
          kCurrentSeat.lastname);
      break;
    }
    printf("%s", kTip);
  }

  IgnoreChar();
  SaveToFile(airplane, length, flight);
}

void ConfirmAssignSeat(struct Seat airplane[], int length, int flight) {
  int index;
  const char kTip[] = "Enter the number of the seat you want confirm, press [0] to end: ";
  printf("%s", kTip);

  while (scanf("%d", &index)) {
    if (!index) 
      break;

    if (index <= 0 && index > length) {
      puts("Enter an integer from 1 to 12, please.");
      printf("%s", kTip);
      continue;
    }
    const struct Seat kCurrentSeat = airplane[index-1];
    if (kCurrentSeat.confirmed) {
      printf("The seat which number is %d already confirmed.\n",
          kCurrentSeat.number);
    } else if (kCurrentSeat.assignable) {
      printf("The seat which number is %d was not assigned.\n",
          kCurrentSeat.number);
    } else {
      printf("The seat you confirmed: flight is %d, number is %d, customer name is %s %s\n", 
          kCurrentSeat.flight,
          kCurrentSeat.number,
          kCurrentSeat.firstname,
          kCurrentSeat.lastname);
      airplane[index-1].confirmed = true;
    }
    printf("%s", kTip);
  }

  IgnoreChar();
  SaveToFile(airplane, length, flight);
}

void DeleteSeat(struct Seat airplane[], int length, int flight) {
  int index;
  const char kTip[] = "Enter the number of the seat you want delete, press [0] to end: ";
  printf("%s", kTip);

  while (scanf("%d", &index)) {
    if (!index) 
      break;

    if (index <= 0 && index > length) {
      puts("Enter an integer from 1 to 12, please.");
      printf("%s", kTip);
      continue;
    }

    const struct Seat kCurrentSeat = airplane[index-1];
    if (kCurrentSeat.assignable) {
      printf("The seat which number is %d already deleted.\n",
          kCurrentSeat.number);
    } else {
      printf("The seat you deleted: flight is %d, number is %d, customer name is %s %s\n", 
          kCurrentSeat.flight,
          kCurrentSeat.number,
          kCurrentSeat.firstname,
          kCurrentSeat.lastname);

      airplane[index-1].assignable = true;
      airplane[index-1].assignable = false;
      airplane[index-1].firstname[0] = '\0';
      airplane[index-1].lastname[0] = '\0';
    }
    printf("%s", kTip);
  }

  IgnoreChar();
  SaveToFile(airplane, length, flight);
}

void IgnoreChar(void) {
  while (getchar() != '\n')
    continue;
}

void SaveToFile(struct Seat airplane[], int length, int flight) {
  FILE *p_seat;
  const int kSize = sizeof (struct Seat);
  GetFilename(flight);
  printf("SaveToFile filename %s.\n", p_filename);
  if ((p_seat = fopen(p_filename, "w+b")) == NULL) {
    fprintf(stderr, "Can't open %s file in w+b mode.\n", p_filename);
    exit(EXIT_FAILURE);
  }
  rewind(p_seat);
  fwrite(airplane, kSize, length, p_seat);
  fclose(p_seat);
}
