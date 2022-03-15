#include <stdio.h>

int main()
{

int stars,i, j;;

printf("Enter the number of stars : ");

scanf("%d", &stars);


/*Logic for inverted Pyramid*/
for (i = stars; i >= 1; i--)

{
	for (j = 1 ; j <= i; j++)
	{	
         	printf("*");
	}
	printf("\n");
}

return 0;
}