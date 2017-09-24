#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNAME 40
#define MEMEBERS 19
#define LINES 100
struct player {
  int number; // 球员号
  char firstname[MAXNAME];
  char lastname[MAXNAME];
  int times_at_bat; // 上场次数
  int hits; // 击中数
  int walks; // 走垒数
  int runs_batted_in; // 跑点数
  float batting_average; // 平均成功率 = hits / walks
};
void initTeam(struct player [], int);
void getPlayerData(struct player [], int, char *);
void computeBattingAverage(struct player [], int);
void showInfo(struct player [], int);

int main(void) {
  struct player team[MEMEBERS];
  struct player temp_player;
  char line_data[LINES];
  FILE * p_book;
  int count;
  int size = sizeof(struct player);

  if ((p_book = fopen("player.dat", "r")) == NULL) {
    fputs("Catn't open player.dat file\n", stderr);
    exit(1);
  }
  rewind(p_book);
  initTeam(team, MEMEBERS);
  while (fgets(line_data, LINES, p_book) != NULL) {
    getPlayerData(team, MEMEBERS, line_data);
  }
  computeBattingAverage(team, MEMEBERS);
  showInfo(team, MEMEBERS);

  return 0;
}

void initTeam(struct player team[], int size) {
  int index = 0;
  while (index < size) {
    team[index].number = 0;
    index++;
  }
}

void getPlayerData(struct player team[], int size, char * line) {
  char * pt = strtok(line, " ");
  const int units_length = 7;
  char * units [units_length];
  int index = 0;
  while (pt) {
    units[index] = pt;
    pt = strtok(NULL, " ");
    index++;
  }
  index = 0;
  while (index < size) {
    int times_at_bat = atoi(units[3]);
    int hits = atoi(units[4]);
    int walks = atoi(units[5]);
    if (team[index].number == atoi(units[0])) {
      team[index].times_at_bat = team[index].times_at_bat + times_at_bat;
      team[index].hits = team[index].hits + hits;
      team[index].walks = team[index].walks + walks;
      break;
    } else if (!team[index].number) {
      team[index].number = atoi(units[0]);
      strcpy(team[index].firstname, units[1]);
      strcpy(team[index].lastname, units[2]);
      team[index].times_at_bat = times_at_bat;
      team[index].hits = hits;
      team[index].walks = walks;
      team[index].runs_batted_in = atoi(units[6]);
      break;
    }
    index ++;
  }
}

void computeBattingAverage(struct player team[], int size) {
  int index = 0;
  while (index < size && team[index].number) {
    struct player current = team[index];
    team[index].batting_average = (float)(current.hits / current.walks);
    index++;
  }
}

void showInfo(struct player team[], int size) {
  int index = 0;
  while (index < size && team[index].number) {
    struct player current = team[index];
    printf("Number is %d\n", current.number);
    printf("Firstname is %s\n", current.firstname);
    printf("Lastname is %s\n", current.lastname);
    printf("Hits is %d\n", current.hits);
    printf("Walks is %d\n", current.walks);
    printf("Runs batted in is %d\n", current.runs_batted_in);
    printf("Batting average is %.2f\n", current.batting_average);
    printf("Time at bat is %d\n", current.times_at_bat);
    printf("-------------------------------------------------------\n");
    index++;
  }
}
