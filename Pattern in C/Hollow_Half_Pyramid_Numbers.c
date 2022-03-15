#include <stdio.h>
int main()
{
int i, j, n, k = 0;
scanf("%d",&n);
for(i = 1; i <= n; i++)
{
for(j = 1; j <= i; j++)
{
if (j == 1 || j == i || i == n)
printf("%d", j);
else
printf(" ");
}
printf("\n");
}
return 0;
}