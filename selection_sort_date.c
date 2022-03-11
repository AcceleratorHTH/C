
#include <stdio.h>

void selection_date_sort();

int main()
{
    
    int d1[] = {27, 20, 9, 27, 28}, m1[] = {6, 8, 8, 6, 2} , y1[] = {2003, 2003, 2003, 2004, 2002};
    int i;
    selection_date_sort(d1, m1, y1, 5);
    
    for (i = 0; i < 5; i++)
        printf("%02d/%02d/%d\n",d1[i], m1[i], y1[i]);
    return 0;
}

void selection_date_sort(int d[], int m[], int y[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
        for (j = i+1; j < size; j++)
        {
            if (y[i] < y[j])
                {
                    temp = y[i];
                    y[i] = y[j];
                    y[j] = temp;

                    temp = m[i];
                    m[i] = m[j];
                    m[j] = temp;

                    temp = d[i];
                    d[i] = d[j];
                    d[j] = temp;
        
                }
            else if (y[i] == y[j] && m[i] < m[j])
                {
                    temp = y[i];
                    y[i] = y[j];
                    y[j] = temp;

                    temp = m[i];
                    m[i] = m[j];
                    m[j] = temp;

                    temp = d[i];
                    d[i] = d[j];
                    d[j] = temp;
        
        
                }
            else if (y[i] == y[j] && m[i] == m[j] && d[i] < d[j])
                {
                    temp = y[i];
                    y[i] = y[j];
                    y[j] = temp;

                    temp = m[i];
                    m[i] = m[j];
                    m[j] = temp;

                    temp = d[i];
                    d[i] = d[j];
                    d[j] = temp;
        
                }
        }

}