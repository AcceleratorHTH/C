#include<stdio.h> 
  
int main(void) {  
  int width,space, i,j;  
  printf("Enter the width: ");  
  scanf("%d",&width);  
  space=2*width-1;  
  for( i=1;i<=space;i++)  
  {  
    for( j=1;j<=space;j++)  
    {  
       if(i==j || j==(space-i+1))  
       {  
         printf("*");  
       }  
       else  
       {  
         printf(" ");  
       }  
    }  
    printf("\n");  
  }  
  return 0;  
}