#include <stdio.h>

int main(void)
{
  int start;
  int end;
  printf("Enter start int number\n");
  scanf("%d",&start);
  end=start+10;
  
  while(start<=end){
    printf("%d\n",start );
    start++;
  }
  return 0;
}