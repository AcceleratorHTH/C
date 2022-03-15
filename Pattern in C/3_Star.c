#include <stdio.h>    
int main() {
    int row, column; 
    int row_length = 11;
    int column_length = 10; 
    int row_middle = 6; 
    
    for (row = 1; row <= row_length; row++) {
        for (column = 1; column <= column_length; column++) {
            if(row == 1 || row == row_middle || row == row_length ) {
                printf("*");
            } else if(column == column_length ) {
                printf("*");    
            } else {
                printf(" ");    
            }
            
        }
        printf("\n");
    }   
    return 0;
}