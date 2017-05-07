#include <stdio.h>

void show_col_row(char, int, int);
int main(void)
{
    show_col_row('m', 10, 10);
    return 0;
}

void show_col_row(char ch, int col, int row)
{
    int _col, _row;
    for(_col=0;_col<col;_col++)
    {
        for(_row=0;_row<row;_row++){
            printf("%c",ch);
        }
        printf("\n");
    }
}
