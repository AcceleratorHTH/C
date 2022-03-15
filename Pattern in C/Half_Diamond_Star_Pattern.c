#include<stdio.h>
  
int main()  
{  
    int max_stars,i,j;  
    printf("Enter the width of diamond: ");  
    scanf("%d",&max_stars);  
for( i=1;i<=max_stars;i++)  
{  
  for( j=1;j<=i;j++) { printf("*"); } printf("\n"); } for( i=max_stars-1;i>=1;i--)  
 {  
   for( j=1;j<=i;j++)  
   {  
     printf("*");  
   }  
   printf("\n");  
 }    
     
    return 0;  
}