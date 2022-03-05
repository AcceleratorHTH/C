#include <stdio.h>

int main()
{
    int a, b, c, d, min;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a % 2 != 0)
        min = a;
    if (b % 2 != 0 && a>b)
        min = b; 
    if (c % 2 != 0 && b>c)
        min = c;
    if (d % 2 != 0 && c>d)
        min = d;
    printf("%d", min);
        
    return 0;
}
