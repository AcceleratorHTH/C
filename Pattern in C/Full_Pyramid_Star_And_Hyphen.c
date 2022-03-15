#include<stdio.h>
int main()
{    
	int i,j,n,k;
    printf("enter the value of n:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
	    for(k=1;k<n-i;k++){
		    printf(" ");
	    }
	    printf("*");
	    for(j=0;j<=i-1;j++){
           	printf("-");
	    }
	    for(j=1;j<i;j++){
	    	printf("-");
	    }
	    if(i>0){
		    printf("*");
	    }
	    printf("\n");
    }
	return 0;
} 