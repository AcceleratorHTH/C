/*

**********
 *********
  ********
   *******
    ******
     *****
      ****
       ***
        **
         *
        **
       ***
      ****
     *****
    ******
   *******
  ********
 *********

 */




#include<stdio.h>  
  
int main(void) {  
    
  int width,i,j,k;  
  printf("Enter the width of arrow: ");  
  scanf("%d",&width);  
  
//  arrow upper part
 for( i=0;i<width;i++)  
 {  
   for( j=0;j<i;j++)  
   {  
       printf(" ");  
   }  
   for( k=1;k<=width-i;k++)  
   {  
     printf("*");  
   }  
   printf("\n");  
 }  
 
// arrow lower part
for( i=1;i<width;i++)  
{  
  for( j=1;j<width-i;j++)  
  {  
    printf(" ");  
  }  
  for( k=1;k<=i+1;k++)  
  {  
    printf("*");  
  }  
  printf("\n");  
}  
  return 0;  
}