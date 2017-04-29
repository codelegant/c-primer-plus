#include <stdio.h>
#include <stdbool.h>

short get_int(void);
bool bad_limits(short begin, short end, short low, short high);
long long sum_squares(short a, short b);

int main(void)
{
    const short MIN=-1000;
    const short MAX=+1000;
    short start;
    short stop;
    long long answer;

    printf("This program computes the sum of the squares of "
            "integers in a ragne.\nThe lower bound should not "
            "be less than -1000 and\nthe upper bound should not "
            "be more than +1000.\nEnter the limits (enter 0 for "
            "both limits to quit):\nlower limit: ");
    start=get_int();
    printf("upper limit: ");
    stop=get_int();

    while(start!=0 && stop!=0)
    {
        if(bad_limits(start, stop, MIN, MAX))
            printf("Please try again.\n");
        else
        {
            answer=sum_squares(start,stop);
            printf("The sum of the squares of the integers from "
                    "from %hd to %hd is %lld\n",start, stop, answer);
        }
        printf("Enter the limits (enter 0 for both limits to quit): \n");
        printf("lower limit: ");
        start=get_int();
        printf("upper limit: ");
        stop=get_int();
    }
    printf("Done.\n");

    return 0;
}

short get_int(void)
{
    short input;
    char ch;

    while(scanf("%hd",&input) != 1)
    {
        while((ch=getchar()) != '\n')
            putchar(ch);
        printf(" is not an interger.\nPlease enter an "
                "integer value, such as 25, -178, or 3: ");
    }
    return input;
}

long long sum_squares(short a, short b)
{
    long long total = 0;
    short i;

    for(i = a; i<=b; i++)
        total += i*i;

    return total;
}

bool bad_limits(short begin, short end, short low, short high)
{
    bool not_good=false;
    
    if(begin>end)
    {
        printf("%hd isn't samller than %hd.\n ",begin, end);
        not_good=true;
    }

    if(begin<low || end<low)
    {
        printf("Values must be %hd or greater.\n",low);
        not_good=true;
    }
    
    if(begin>high || end>high)
    {
        printf("Values must be %hd or less.\n",high);
        not_good=true;
    }

    return not_good;
}
