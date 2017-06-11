#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    char temp[BUFFER_SIZE];
    FILE *fp;
    if(argc < 3)
    {
        fprintf(stderr, "At least two arguments\n");
        exit(EXIT_FAILURE);
    }
    if(!(fp = fopen(argv[2], "r")))
    {
        fprintf(stderr, "Failed opening %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while(fgets(temp, BUFFER_SIZE, fp) && strstr(temp, argv[1]))
        fputs(temp, stdout);
    return 0;
}
