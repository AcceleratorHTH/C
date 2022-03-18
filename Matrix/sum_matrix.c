#include<stdio.h>
#include<conio.h>
main()
{
    int a[10][10],b[10][10],c[10][10];
    int i,j,m,n;
    printf("nhap so hang m="); scanf("%d",&m);
    printf("nhap so cot n="); scanf("%d",&n);
    printf("nhap vao ma tran:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
     for(i=0;i<m;i++)
     {
        for(j=0;j<n;j++)
              {
            c[i][j]=a[i][j]+b[i][j];
        }
    }    
    printf("\nMa tran sau cong:\n");
    for(i=0;i<m;j++)
    {    
        for(j=0;j<n;j++)
        {
            printf("%5d",c[i][j]);
        }
        printf("\n");
    }
    getch();
}