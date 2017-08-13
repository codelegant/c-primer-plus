#include <stdio.h>
struct name {
    char first[20];
    char last[20];
};
struct bem {
    int limbs;
    struct name title;
    char type[30];
};
void showInfo (struct bem *);

int main(void){
    struct bem *pb;
    struct bem deb = {
        6,
        {"Berbnazel", "Gwolkapwolk"},
        "Arcturan"
    };
    pb = &deb;
    printf("%s\n", pb->type + 2);
    showInfo(pb);
    return 0;
}

void showInfo (struct bem *deb){
    printf("%s %s is a %d-limbed %s\n", deb->title.first, deb->title.last, deb->limbs, deb->type);
}
