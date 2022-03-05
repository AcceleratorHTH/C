#include<stdio.h>

int binaryFind(int search, int key[], int size)
{
	int rc = -1, i, low = 0, high = size - 1;

	do
	{
		//calculate mid-element
		i = (low + high + 1) / 2;
		if (search < key[i])
			//reset high element
			high = i - 1;
		else if (search > key[i])
			//reset low element
			low = i + 1;
		else
			//found it
			rc = i;
	} while (rc == -1 && low <= high);
   
	return rc;
}

int main()
{
   int key[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int search, size;
   search = 8;
   size = 10;
   printf("The number %d is in position %d", search, binaryFind(search, key, size));

   return 0;
   
}