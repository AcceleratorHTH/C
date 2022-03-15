#include<stdio.h>   
  
int main()  
{  
    int height,i,j;  
    printf("Enter the height of Pyramid: ");  
    scanf("%d",&height);  
    for(i=height;i>=1;i--)  
    {  
      for( j=1;j<=i;j++)  
      {  
         if(j==1 || j==i || i==height)  
          printf("*");  
          else  
          printf(" ");  
      }  
      printf("\n");  
    }  
    return 0;  
}