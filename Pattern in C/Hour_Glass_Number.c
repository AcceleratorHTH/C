#include<stdio.h>
main()
{
int i,j,left,right,k,rightcount,count,rows,alpha;
printf("Enter number of rows\n");
scanf("%d",&rows);
count=0;
left=rows;
right=rows-1;

for(i=rows;i>=1;i--)
{
 if(i!=1)
 {
       for(k=1;k<=count;k++)
       {
           printf(" ");
        }
       for(j=1;j<=left;j++)
       {
          printf("%d",j);
       }
       left--;
          for(j=right;j>=1;j--)
          {
            printf("%d",j);
          }
        right--;
        printf("\n");
       count++;   
 }
}
count=rows-1;
left=1;
right=0;
for(i=1;i<=rows;i++)
{
    for(k=1;k<=count;k++)
    {
        printf(" ");
    }
    for(j=1;j<=left;j++)
    {
        printf("%d",j);
    }
    left++;
       if(i!=1)
       {
               for(j=right;j>=1;j--)
             {
            printf("%d",j);
                 }
             
       }
        right++;
       printf("\n");
       count--;    
}
}
