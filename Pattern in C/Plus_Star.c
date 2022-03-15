#include<stdio.h>  
  
int main(void) {  
  int height,i,j;  
  printf("Enter the height (odd): ");  
  scanf("%d", &height);  
  for( i=1;i<=height;i++)  
  {  
    if(i==((height/2)+1))  
    {  
      for( j=1;j<=height;j++)  
      {  
        printf("+");  
      }  
   
    }  
    else  
    {  
    for( j=1;j<=height/2;j++)  
    {  
      printf(" ");  
    }  
    printf("+");  
    }  
    printf("\n");  
  }  
  return 0;  
}