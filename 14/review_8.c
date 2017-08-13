#include <stdio.h>
#include <string.h>
struct fullname {
    char fname[20];
    char lname[20];
};
struct bard {
    struct fullname name;
    int born;
    int died;
};

int main(void){
    struct bard willie;
    struct bard *pt = &willie;

    printf("Enter the born:");
    scanf("%d", &(willie.born));
    //scanf("%d", &(pt->born));
    printf("willie.born = %d\n", willie.born);
    printf("pt->born = %d\n", pt->born);

    printf("Enter the firstname:");
    //scanf("%s", willie.name.fname);
    scanf("%s", pt->name.fname);
    printf("willie.name.fname = %s\n", willie.name.fname);
    printf("pt->name->fname = %s\n", pt->name.fname);

    printf("Enter the lastname:");
    //scanf("%s", willie.name.lname);
    scanf("%s", pt->name.lname);
    printf("willie.name.lname = %s\n", willie.name.lname);
    printf("pt->name->lname = %s\n", pt->name.lname);

    printf("Third character of lastname is %c.\n", willie.name.lname[2]);
    //printf("Third character of lastname is %s.\n", pt->name.lname+2);
    printf("The count of fullname is %lu.\n", strlen(willie.name.fname) + strlen(willie.name.lname));

    return 0;
}
