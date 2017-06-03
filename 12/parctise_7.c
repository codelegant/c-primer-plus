/* manydice.c -- multiple dice rolls                    */
/* compile with diceroll.c                              */
#include <stdio.h>
#include <stdlib.h>              /* for library srand() */
#include <time.h>                /* for time()          */
#include "diceroll.h"            /* for roll_n_dice()   */
/* and for roll_count  */
int main(void)
{
    int dice;
    int roll;
    int sides;
    int sets;

    srand((unsigned int) time(0)); /* randomize seed      */
    printf("Enter the number of sets; enter q to stop.\n");
    while (scanf("%d", &sets) == 1 && sides > 0)
    {
        printf("How many sides and how many dice?\n");
        scanf("%d %d", &sides, &dice);

        int sets_arr[sets];
        int index=0;
        while(index<sets)
            sets_arr[index++]= roll_n_dice(dice, sides);

        printf("Here are %d sets of %d %d-sided throws.\n",
                sets, dice, sides);
        index=0;
        while(index<sets)
            printf("%4d",sets_arr[index++]);
        printf("\nHow many sides? Enter q to stop.\n");
    }
    printf("The rollem() function was called %d times.\n",
            roll_count);           /* use extern variable */

    printf("GOOD FORTUNE TO YOU!\n");

    return 0;
}
