#include <stdio.h>

int main()

{

int i,j,k,N,count=0;

scanf("%d",&N);

for(i=1;i<=N;i++)

{

k=1;

for(j=0;j<i;j++)

{

printf("%d",i);

if(k<i)

{

printf("*");

k=k+1;

}

}

printf("n");

}

for(i=N;i>0;i--)

{

k=1;

for(j=0;j<i;j++)

{

printf("%d",i);

if(k<i)

{

printf("*");

k=k+1;

}

}

printf("n");

}

return 0;

}