#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LENGTH 256

int main(int args, char *argc[])
{
   char line[LENGTH];
   FILE *fp;
   if(args < 3)
   {
       fprintf(stderr, "The arguments should be two.\n");
       exit(EXIT_FAILURE);
   }
   if((fp = fopen(argc[2], "r")) == 0)
   {
       fprintf(stderr, "Can't open file %s\n", argc[2]);
       exit(EXIT_FAILURE);
   }
   while(fgets(line, LENGTH, fp) != 0)
   {
       if(strstr(line, argc[1]) != 0)
           fputs(line, stdout);
   }
   fclose(fp);
   return 0;
}
