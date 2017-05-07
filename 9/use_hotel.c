#include<stdio.h>
#include"hotel.h"

int main(void)
{
    int nights;
    double hotel_rate;
    int code;

    while((code=menu())!=QUIT)
    {
        switch(code)
        {
            case 1:hotel_rate=HOTEL_1;
                   break;
            case 2:hotel_rate=HOTEL_2;
                   break;
            case 3:hotel_rate=HOTEL_3;
                   break;
            case 4:hotel_rate=HOTEL_4;
                   break;
            default:hotel_rate=0.0;
                    printf("Oops!\n");
                    break;
        }
        printf("hotel_rate is %.2f\n",hotel_rate);
        nights=get_nights();
        show_price(hotel_rate,nights);
    }
    printf("Thank you and goodbye.");
    return 0;
}
