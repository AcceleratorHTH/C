#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void removeDuplicates(int num[] , int *n)
{
    int i, j, k;
    
    for (i = 0; i < *n; i++)
        for (j = i+1; j < *n; j++)
            if (num[i] == num[j])
            {
                for (k = j; k < *n - 1; k++)
                        num[k] = num[k+1];
                (*n)--;
                j--;
            }
}

int main() {

    int n, i;
    scanf("%d", &n);
    int num[n];
    for(i = 0; i < n; i++)
        scanf("%d", &num[i]);
    removeDuplicates(num, &n);
    for(i = 0; i < n; i++)
        printf("%d ", num[i]);
    
    
    return 0;
}

