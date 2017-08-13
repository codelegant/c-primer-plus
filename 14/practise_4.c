#include <stdio.h>
#include <string.h>
#define NAME_LENGTH 50
#define ROW 5
struct fullname {
  char firstname[NAME_LENGTH];
  char middelname[NAME_LENGTH];
  char lastname[NAME_LENGTH];
};
struct person {
  unsigned long social_security_number;
  struct fullname fullname;
};
void ShowInfo(struct person [], int);

int main(void) {
  struct person people[ROW] = {
    {374853374894110, {"Lai", "Chuan", "feng"}},
    {374853374894120, {"Xiao", "Chai", "Yun"}},
    {374853374894130, {"Yiao", "Lhai", "Wun"}},
    {374853374894140, {"Liao", "Shai", "Sun"}},
    {374853374894150, {"Siao", "", "Iun"}}
  };
  ShowInfo(people, ROW);
  return 0;
}

void ShowInfo(struct person people[], int length) {
  for (int i=0; i<length; i++) {
    struct person curr = people[i];
    printf(
        "%s, %s %c%c - %ld\n",
        curr.fullname.firstname,
        curr.fullname.lastname,
        curr.fullname.middelname[0],
        strlen(curr.fullname.middelname)>0 ? '.' :'\0',
        curr.social_security_number
        );
  }
}
