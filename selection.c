#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

#define DEBUG 


void Selectionsort(int array[], int arraysize)
{
	printf("start Selectionsort ... \n");
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


