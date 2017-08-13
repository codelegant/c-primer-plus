#include <stdio.h>
#define MAXTITLE 41
#define MAXAUTL 31
struct book{
    char title[MAXTITLE];
    char author[MAXAUTL];
    int count;
    float value;
};
const char * msgs[2]= {
    "This is not a book",
    "but name is null"
};

int main(void) {
    struct book gift = {.value=10.99};
    printf("%s\n", msgs[1]);
    return 0;
}
