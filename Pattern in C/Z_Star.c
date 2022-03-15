#include <stdio.h>    
int main() {
    int row, column; 
    int row_length = 10; int column_length = 10;  
    
    for (row = 1; row <= row_length; row++) {
        for (column = 1; column <= column_length; column++) {
            if(row == 1 || row == row_length ) {
                printf("*");
            } else if(column == (row_length-row)+1) {
                printf("*");
            } else {
                printf(" ");    
            }
        }
        printf("\n");
    }
    return 0;
}