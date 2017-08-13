#include <stdio.h>

double func_1 (double, double);
double func_2 (double, double);
double func_3 (double, double);
double func_4 (double, double);

int main(void){
    double (* funcs[4])(double,double) = {func_1, func_2, func_3, func_4};
    printf("%lf", funcs[1](1.2, 1.3));
    return 0;
}

double func_1 (double a, double b){
    return 1.232;
}
double func_2 (double a, double b){
    return 1.232;
}
double func_3 (double a, double b){
    return 1.232;
}
double func_4 (double a, double b){
    return 1.232;
}
