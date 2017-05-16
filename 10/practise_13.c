#include <stdio.h>
#define ROWS 3
#define COLS 5
void get_arr(int, int, float [*][*]);
float average_column(int, float *);
float average_arr(int, int, float [*][*]);
float maximum_ele(int, int, float [*][*]);
void print_arr(int, int, float [*][*]);

int main(void)
{
    int row;
    float arr[ROWS][COLS];
    get_arr(ROWS, COLS, arr);
    for(row=0; row<ROWS; row++)
        printf("第%d行的平均值是：%.2f\n", row+1, average_column(COLS, arr[row]));
    printf("数组的平均值是：%.2f\n",average_arr(ROWS, COLS, arr));
    printf("数组的最大值是：%.2f\n",maximum_ele(ROWS, COLS, arr));
    print_arr(ROWS, COLS, arr);
}

void get_arr(int rows, int cols, float arr[rows][cols])
{
    printf("请输入15个数字，数字之间用空格分隔，回车完成输入。\n");
    int r;
    int c;

    for(r=0; r<rows; r++)
        for(c=0; c<cols; c++)
            scanf("%f",&arr[r][c]);
}

float average_column(int cols, float arr[])
{
    int c;
    float total=0;
    for(c=0; c<cols; c++)
        total+=arr[c];
    return total;
}

float average_arr(int rows, int cols, float arr[rows][cols])
{
    int r;
    int c;
    float total=0;

    for(r=0; r<rows; r++)
        for(c=0; c<cols; c++)
            total+=arr[r][c];
    return total/rows/cols;
}

float maximum_ele(int rows, int cols, float arr[rows][cols])
{
    int r;
    int c;
    float maximum=0;

    for(r=0; r<rows; r++)
        for(c=0; c<cols; c++)
            if(maximum<arr[r][c])
                maximum=arr[r][c];
    return maximum;
}

void print_arr(int rows, int cols, float arr[rows][cols])
{
    int r;
    int c;

    for(r=0; r<rows; r++)
        for(c=0; c<cols; c++)
            printf("第%d行第%d列的值是：%.2f\n",r+1, c+1, arr[r][c]);
}
