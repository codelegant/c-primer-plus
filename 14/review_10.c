#include <stdio.h>
typedef struct gas{
    float distance;
    float gals;
    float mpg;
} GAS;

GAS mpg_by_struct(GAS);
void mpg_by_address(GAS *);

int main(void){
    GAS gas_1 = mpg_by_struct((GAS){100, 6});
    printf("mpg is %.2f\n", gas_1.mpg);

    GAS gas_2={ 110,6 };
    mpg_by_address(&gas_2);
    printf("mpg is %.2f\n", gas_2.mpg);
    return 0;
}

GAS mpg_by_struct(GAS gas){
    gas.mpg=gas.distance/gas.gals;
    return gas;
}

void mpg_by_address(GAS *pt){
    pt->mpg=pt->distance/pt->gals;
}
