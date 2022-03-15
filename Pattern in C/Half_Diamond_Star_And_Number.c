#include <stdio.h>

int main()
{
	int i, j, N;

	printf("Enter the number of rows : ");
	scanf("%d", &N);
	printf("*\n");

	for(i=1; i<=N; i++)
		{
			for(j=1; j<=i; j++)
				{
					if(j == 1)
						printf("*");
					printf("%d", j);
				}
			for(j=i-1; j>=1; j--)
				{		
					printf("%d", j);
				}
			printf("*");
			printf("\n");
		}

for(i=N-1; i>=1; i--)
	{
		for(j=1; j<=i; j++)
			{
				if(j == 1)
					printf("*");
				printf("%d", j);
			}
		for(j=i-1; j>=1; j--)
			{
				printf("%d", j);
			}
		printf("*");
		printf("\n");
	}
	printf("*\n");
	return 0;
}