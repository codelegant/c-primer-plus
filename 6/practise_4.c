#include <stdio.h>

int main(void)
{
    char letter;
    short i, j, k, m;
    printf("Enter a uppercase letter: ");
    scanf("%c",&letter);

    i=(short)letter-(short)'A';
    for(j=0; j<=i; j++){
      for(k=i-j; k>0;k--)
        printf(" ");
      
      for(k=(short)'A';k<=(short)'A'+j;k++)
        printf("%c", k);

      for(m=(short)'A'+j-1;m>=(short)'A';m--)
        printf("%c", m);

      printf("\n");
    }

    return 0;
}