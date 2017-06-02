#include <stdio.h>
void set_mode(int *);
void get_info(int, int *, float *);
void show_info(int, int , float );

int main(void)
{
    int mode;
    int distance;
    float fuel;
    printf("Enter 0 for metrice mdoe, 1 for US mode: ");
    scanf("%d", &mode);
    while(mode >= 0)
    {
        set_mode(&mode);
        get_info(mode, &distance, &fuel);
        show_info(mode, distance, fuel);
        printf("Enter 0 for metrice mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}

void set_mode(int *mode)
{
    if(*mode>1)
    {
        printf("Invalid mode specified. Mode 1(US) used.\n");
       *mode=1;
    }
}

void get_info(int mode, int *distance, float *fuel)
{
    if(mode==0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%d", distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", fuel);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%d", distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", fuel);
    }
}

void show_info(int mode, int distance, float fuel)
{
    if(mode==0) 
    {
        printf("Fuel consumption is %.2f liters per 100 km.\n",
                fuel/distance*100);
    }
    else
    {
        printf("Fuel consumed is %.2f miles per gallon.\n", distance/fuel);
    }
}
