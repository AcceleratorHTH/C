#include <stdio.h>  
  
int main()  
{  
    int height,space=1,i,j,k;  
    printf("Enter the height of pyramid: ");  
    scanf("%d",&height);  
  
   for( i=height;i>=1;i--)  
   {  
       for( j=1;j<space;j++)  
       {  
           printf(" ");  
       }  
       for( k=1;k<=2*i-1;k++)  
       {  
          if(k==1 || k==2*i-1 || i==height)  
           printf("*");  
           else  
           printf(" ");  
       }  
       space++;  
     
      printf("\n");  
    }  
    return 0;  
}