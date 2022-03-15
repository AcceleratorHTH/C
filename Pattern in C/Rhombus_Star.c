#include<stdio.h>
  
int main()  
{  
    int rows, i,j,k;  
    printf("Enter rows: ");  
    scanf("%d",&rows);  
    for( i=rows;i>=1;i--)  
    {  
        for( j=1;j<=i-1;j++)  
        {  
            printf(" ");  
        }  
        for( k=1;k<=rows;k++)  
        {  
            printf("*");  
        }  
        printf("\n");  
    }  
    return 0;  
}