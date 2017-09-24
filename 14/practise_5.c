#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define NAME_LENGTH 20
#define CSIZE 4
typedef struct name {
  char firstname[NAME_LENGTH];
  char lastname[NAME_LENGTH];
} NAME;
typedef struct student {
  NAME name;
  float grades[3];
  float average;
} STUDENT;

void GetInfo(STUDENT [], int);
void CountAverage(STUDENT [], int);
void ShowInfo(STUDENT [], int);
void ShowAverage(STUDENT [], int);

int main(void) {
  STUDENT students[CSIZE] = {
    {{"Lai", "Chuanfeng"}},
    {{"Xiao", "Chaiyun"}},
    {{"Lai", "Shuyuan"}},
    {{"Lai", "Aiyun"}}
  };
  GetInfo(students, CSIZE);
  CountAverage(students, CSIZE);
  ShowInfo(students, CSIZE);
  ShowAverage(students, CSIZE);
  return 0;
}

void GetInfo(STUDENT students [], int size) {
  char fullname[40];
  bool student_is_exsit = false;
  puts("Please [enter] at the start of a line to stop.");
  printf("Enter the name of student: ");
  while (gets(fullname) && fullname[0] != '\0') {
    student_is_exsit = false;
    for (int i=0; i < size; i++) {
      char temp_name[40];
      STUDENT current = students[i];
      strcat(temp_name, current.name.firstname);
      strcat(temp_name, " ");
      strcat(temp_name, current.name.lastname);
      if (!strcmp(fullname, temp_name)) {
        temp_name[0] = '\0';
        int j = 3;
        student_is_exsit = true;
        printf("Enter three grades of %s: \n", fullname);
        while (j--) scanf("%f", &students[i].grades[j]);
        // 清除上面分数输入后的回车
        while(getchar() != '\n') continue; 
        break;
      } 
      temp_name[0] = '\0';
    }
    if(!student_is_exsit)
      printf("There has no student which fullname is %s.\n", fullname);
    puts("--------------------------------------------------------");
    printf("Enter the name of student: ");
  }

}
void CountAverage(STUDENT students [], int size) {
  for (int i = 0; i < size; i++) {
    float total = 0;
    for (int j = 0; j < 3; j++) {
      total += students[i].grades[j];
    }
    students[i].average = total/3;
  }
}
void ShowInfo(STUDENT students [], int size) {
  for (int i = 0; i < size; i++) {
    printf("Fullname is %s %s, grades is ", students[i].name.firstname,
        students[i].name.lastname);
    for (int j =0; j < 3; j++) {
      printf("%.2f ", students[i].grades[j]);
    }
    printf(", average is %.2f\n", students[i].average);
  }
}
void ShowAverage(STUDENT students [], int size) {
  float total = 0;
  for (int i = 0; i < size; i++) {
    total += students[i].average;
  }
  printf("Class average is %.2f\n", total/size);
}
