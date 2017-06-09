#include <stdio.h>
#include <stdlib.h>
int main(int args, char *argc[])
{
    FILE *fp;
    float temp;
    float sum=0.0;
    int ct=0; 
    if(args == 1)
        fp = stdin;
    else 
    {
        if((fp = fopen(argc[1],"r")) == 0)
        {
            fprintf(stderr, "Can't open %s\n", argc[1]);
            exit(EXIT_FAILURE);
        }
    }
    while(fscanf(fp, "%f", &temp) == 1)
    {
        sum += temp;
        ct++;
    }
    if(ct > 0)
        printf("The avarge is %f.\n", sum / ct);
    else
        printf("Not number input");
    
    if(args>2)
        fclose(fp);

    return 0;
}
