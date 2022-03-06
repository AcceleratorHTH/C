// Viet chuong trinh nhap vao mot xau ki tu va loai bo cac dau cach

#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    int i, j;
    
    scanf("%[^\n]", s);
    
    // sd   sd s  a
    // sdsdsa\0s  a
    
    for (j = 0, i = 0; s[i]; i++)
        if (s[i] != ' ')
            s[j++] = s[i];
    s[j] = '\0';
    
    printf("%s", s);

    return 0;
}