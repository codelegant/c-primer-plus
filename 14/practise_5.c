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
  float grade[3];
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
    {{"Lai", "Xuyuan"}}
  };
  GetInfo(students, CSIZE);
  //CountAverage(students, CSIZE);
  //ShowInfo(students, CSIZE);
  //ShowAverage(students, CSIZE);
  return 0;
}

void GetInfo(STUDENT students [], int size) {
  char fullname[40];
  bool student_is_exsit = false;
  puts("Please [enter] at the start of a line to stop.");
  printf("Enter the name of student: ");
  while (gets(fullname) && fullname[0] != '\0') {
    student_is_exsit = false;
    printf("1 fullname is %s.\n", fullname);
    printf("1 student_is_exsit is %d.\n", student_is_exsit);
    for (int i=0; i<size; i++) {
      char temp_name[40];
      STUDENT current = students[i];
      strcat(temp_name, current.name.firstname);
      strcat(temp_name, " ");
      strcat(temp_name, current.name.lastname);
      printf("2 fullname is %s.\n", fullname);
      printf("2 student_is_exsit is %d.\n", student_is_exsit);
      if (!strcmp(fullname, temp_name)) {
        int j=3;
        student_is_exsit = true;
        printf("Enter three grades of %s: \n", fullname);
        while (j--) scanf("%f", &current.grade[j]);
        // 清除上面分数输入后的回车
        while(getchar() != '\n') continue; 
        break;
      } 
    }
    if(!student_is_exsit)
      printf("There has no student which fullname is %s.\n", fullname);
    printf("3 fullname is %s.\n", fullname);
    printf("3 student_is_exsit is %d\n", student_is_exsit);
    puts("--------------------------------------------------------");
    printf("Enter the name of student: ");
  }

}
void CountAverage(STUDENT students [], int size) {
}
void ShowInfo(STUDENT students [], int size) {
}
void ShowAverage(STUDENT students [], int size) {
}
