#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 
void swap(int array[],int a ,int b)
{ 
int temp = array[b];    
array[b] = array[a];    
array[a] = temp;
}

void Selectionsort(int array[], int arraysize)
{
	int i,j;
	int minpos;

	if((array == NULL) || (arraysize <= 1))
		return;
	for(i=0;i<arraysize-1;i++)
	{    
		minpos = i;    
		for(j=i+1;j<arraysize;j++)    
		{        
			if(array[minpos] > array[j])            
				minpos = j;    
		}   
		swap(array, i, minpos);
#ifdef DEBUG
		printarray(array,arraysize);
#endif
	}
}

void printarray(int array[],int arraysize)
{
	int i;
	for( i=0;i<arraysize;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
void main()
{
	int unsortarray[] = {90,87,56,34,97,2,6,8,1};
	Selectionsort(unsortarray,9);
	printarray(unsortarray,9);

}

