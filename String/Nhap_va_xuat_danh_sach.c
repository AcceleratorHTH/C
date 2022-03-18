#include <stdio.h>
#include <string.h>
 
/*
    Nhập/ xuất danh sách n sinh viên
*/
 
int main(){
    char arr[1000][50]; // mảng chứa tối đa 1000 sinh viên, mỗi tên sinh viên dài tối đa 50 ký tự
    int n;
    do{
        printf("\nNhap so luong SV: ");
        scanf("%d", &n);
    }while(n < 1);
 
    // Nhập danh sách
    for(int i = 0; i < n; i++){
        printf("Ten SV thu %d: ", i+1);
        fflush(stdin);
        gets(arr[i]);
    }
 
    // Xuất danh sách
    for(int i = 0; i < n; i++){
        printf("\nTen SV thu %d: %s", i+1, arr[i]);
    }
}