#include<stdio.h>
int main(){
    int i,j,k,n;
    printf("enter the value of n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i%2==0){
	        for(k=1;k<=i;k++){
		            printf("-");
		    }
        }else{
            for(k=1;k<=i;k++){
		        printf("*");
		    }
        }
		printf("\n");
    }
    for(i=n;i>1;i--)
    {
        if(i%2==0){
	        for(k=i;k>1;k--){
		            printf("*");
	        }
        }
        else{
            for(k=i;k>1;k--){
		        printf("-");
	        }
        }
	    printf("\n");
    }
    return 0;
}	