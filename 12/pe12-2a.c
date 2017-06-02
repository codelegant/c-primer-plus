#include <stdio.h>
static int mode;
static int distance;
static float fuel;

void set_mode(int _mode)
{
    if(_mode>1)
    {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        mode=1;
    }
    else{
        mode=_mode; 
    }
}

void get_info(void)
{
    if(mode==0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%d", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", &fuel);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%d", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", &fuel);
    }
}

void show_info(void)
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
