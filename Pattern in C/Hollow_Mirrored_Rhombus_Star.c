#include <stdio.h>
   
int main()  
{  
    int rows, i,j,k;  
    printf("Enter rows: ");  
    scanf("%d",&rows);  
    for( i=1;i<=rows;i++)  
    {  
        for( j=1;j<i;j++)  
        {  
            printf(" ");  
        }  
        for( k=1;k<=rows;k++)  
        {  
         if(i==1 || i==rows || k==1 || k==rows)  
           printf("*");  
            else  
            printf(" ");  
        }  
        printf("\n");  
    }  
    return 0;  
}