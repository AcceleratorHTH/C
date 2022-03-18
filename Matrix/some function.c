#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




int TongCacSoChan(int a[][100], int m, int n)
{
   int sum = 0;
   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
         if(a[i][j]%2==0)
            sum += a[i][j];
   return sum;
}



bool SoNguyenTo(int soA)
{
    if (soA < 2)
    {
        return false;
    }
    else
    {
        for (int i = 2; i <= sqrt((float)soA); i ++)
        {
            if (soA%i==0)
            {
                return false;
            }
        }
    }
    return true;
}
 
int DemSoLuongSNT(int a[][100], int m, int n)
{
   int dem = 0;
   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
         if(SoNguyenTo(a[i][j])) dem++;
   return dem;
}
 
void LietKeSNT(int a[][100], int m, int n)
{
   int dem = 0;
   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
         if(SoNguyenTo(a[i][j])) printf("%d\t", a[i][j]);
}



void XoaDong(int a[][100], int &m, int n, int r)
{
   for(int i=r;i<m-1;i++)
      for(int j=0;j<n;j++)
         a[i][j]=a[i+1][j];
   m--;
}
 
void XoaCot(int a[][100], int m, int &n, int c)
{
   for(int i=0;i<m;i++)
      for(int j=c;j<n-1;j++)
         a[i][j]=a[i][j+1];
   n--;
}



void swap(int &a, int &b)
{
   int temp = a;
   a = b;
   b = temp;
}
 
void DoiCho2Hang(int a[][100], int m, int n, int row1, int row2)
{
   if((row1>=0 && row1<m)&&(row2>=0 && row2<m))
      for(int j=0;j<n;j++)
         swap(a[row1][j],a[row2][j]);
}
 
void DoiChoHaiCot(int a[][100], int m, int n, int column1, int column2)
{
   if((column1>=0 && column1<n)&&(column2>=0 && column2<n))
      for(int i=0;i<m;i++)
         swap(a[i][column1],a[i][column2]);
}
 


 //max min tren duong cheo chinh
int Max(int a[][100], int n)
{
   int max = a[0][0];
   for(int i = 1; i < n; i++)
      if(a[i][i] > max)
         max = a[i][i];
   return max;
}
 
int Min(int a[][100], int n)
{
   int min = a[0][0];
   for(int i = 1; i < n; i++)
      if(a[i][i] < min)
         min = a[i][i];
   return min;
}



int main()
{

}