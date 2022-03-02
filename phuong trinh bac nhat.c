#include <stdio.h>

int main()
{
	float a,b;
	printf("Nhap a va b\n");
	scanf("%f %f", &a, &b);
	if (a == 0)
	{
		if (b == 0)
			printf ("Phuong trinh co vo so nghiem");
		else 
			printf("Phuong trinh vo nghiem");
	}
	else if (b == 0 )
		printf("Phuong trinh co nghiem la: 0");
	else	
		printf("Phuong trinh co nghiem la:%g", -b/a);

	return 0;

}



