#include <stdio.h>
#include <string.h>

int main()

{
    char num[8];
    scanf("%s", num);
    for (int i=strlen(num)-1;i>=0;--i)
        if (i==strlen(num)/2)
        
        {
            printf("%c", num[i]);
            printf(" ");
        }
        
        else
        
        {
            printf("%c", num[i]);
            if (i<strlen(num)-1 && i != 1 && i%2==1)
                printf ("\n");
            
        }
    return 0;
}


