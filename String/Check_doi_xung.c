#include <stdio.h>
#include <string.h>
char doixung(char s1[100])
{
    int i;
    for (i = 0; i < strlen(s1) / 2; i++)
    {
        if (s1[i] != s1[strlen(s1) - 1 - i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char s1[100];
    printf("xin moi ban nhap chuoi\n");
    gets(s1);
    if (doixung(s1) == 0)
    {
        printf("chuoi vua nhap khong phai chuoi doi xung\n");
    }
    if (doixung(s1) == 1)
    {
        printf("chuoi vua nhap la chuoi doi xung\n");
    }
}