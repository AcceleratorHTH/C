/* Viet chuong trinh nhap vao hai ma tran a, b va thuc hien nhan a*b
+ input:
2 3
1 2 3
1 0 2
3 4
1 2 3 1
1 0 2 3
1 1 2 0
+ output:
    2 4
    6 5 x x
    x x x x
    
    hoac in ra -1 neu phep nhan khong thuc hien duoc
+ constraints:
    - kich thuoc cua cac ma tran nho hon 100
    - gia tri cua cac phan tu la cac so tu nhien nho hon 1000
*/
    
#include <stdio.h>

void read_matrix(int a[][100], int *ar, int *ac);
void print_matrix(int a[][100], int ar, int ac);
int multiply(int a[][100], int b[][100], int c[][100], int ar, int ac, int br, int bc);


int main()
{
    int a[100][100], b[100][100], c[100][100], ar, ac, br, bc, i, j;
    
    read_matrix(a, &ar, &ac);
    read_matrix(b, &br, &bc);
    
    if (multiply(a, b, c, ar, ac, br, bc))
    {
        printf("%d %d\n", ar, ac);
        print_matrix(c, ar, bc);
    }
    else
        printf("-1");
    
    return 0;
}


void read_matrix(int a[][100], int *ar, int *ac)
{
    int i, j;
    
    scanf("%d%d", ar, ac);
    for (i = 0; i < *ar; i++)
        for (j = 0; j < *ac; j++)
            scanf("%d", &a[i][j]);
}


void print_matrix(int a[][100], int ar, int ac)
{
    int i, j;
    
    for (i = 0; i < ar; i++)
    {
        for (j = 0; j < ac; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }    
}


int multiply(int a[][100], int b[][100], int c[][100], int ar, int ac, int br, int bc)
{
    int i, j, k;
    
    if (ac != br) // khong thuc hien duoc phep nhan
        return 0;
        
    for (i = 0; i < ar; i++)
        for (j = 0; j < bc; j++)
            for (c[i][j] = 0, k = 0; k < ac; k++)
                c[i][j] += a[i][k] * b[k][j];
                
    return 1;
}