#include <stdio.h>

void bubble_sort(int a[], int size)
{
    int i, j;
    int temp;
    for (i = size - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (a[j] < a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {1, 3, 2, 5, 4}, i;
    bubble_sort(a, 5);
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
    
    return 0;
}