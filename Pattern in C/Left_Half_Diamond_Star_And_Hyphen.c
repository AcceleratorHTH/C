#include<stdio.h>
int main(){
    int i,j,k,n;
    printf("enter the value n:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
	    for(j=0;j<n-i;j++){
		        printf(" ");
		}
		if(i%2==0){
	        for(k=0;k<=i;k++){
		        printf("*");
		    }
        }else{
            for(k=0;k<=i;k++){
		        printf("-");
		    }
        }
		printf("\n");
    }
    for(i=n-1;i>0;i--)
    {
	    for(j=n;j>=i;j--){
	    	printf(" ");
	    }
	    if(i%2==0){
	        for(k=i;k>0;k--){
		        printf("-");
	        }
	    }else{
	        for(k=i;k>0;k--){
		        printf("*");
	        }
	    }
	    printf("\n");
    }
    return 0;
}	 