#include <stdio.h>
#include <string.h>
#define MAX_LEN 50

void get_names(char names[][MAX_LEN], int *n)
{
    int i;
    
    scanf("%d", n);
    for (i = 0; i < *n; i++)
    {
        printf("Name %d: ", i+1);
        scanf("%*c%[^\n]", names[i]);
    }
}

int main()
{

    char names[100][MAX_LEN];
    int i, n, imax;
    get_names(names, &n);

    for( imax = 0, i = 1; i < n; i++)
        if (strlen(names[imax]) < strlen(names[i]))
            imax = i;
    printf("%s", names[imax]);

    return 0;

}