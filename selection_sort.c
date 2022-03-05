#include <stdio.h>

void selection_sort(int a[], int size)
{
    int i, j, jmax;
    int max;
    for (i = 0; i < size - 1; i++)
    {
        max = a[0];
        jmax = 0;
        for (j = 1; j < size - i; j++)
            if (a[j] > max)
            {
                max = a[j];
                jmax = j;
            }
        if (jmax != size - i - 1)
        {
            max = a[size - i - 1];
            a[size - i - 1] = a[jmax];
            a[jmax] = max;
        }
    }
}

int main()
{
    int a[] = {1, 3, 2, 5, 4}, i;
    selection_sort(a, 5);
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
    
    return 0;
}