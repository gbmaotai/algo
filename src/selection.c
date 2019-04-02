#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

//#define DEBUG 

//min
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

//min and max
void Selectionsort2(int array[], int arraysize)
{
	printf("start Selectionsort2 ... \n");
	int i,j;
	int minpos,maxpos;

	if((array == NULL) || (arraysize <= 1))
		return;
	for(i=0;i<arraysize/2;i++)
	{    
		minpos = i;    
		maxpos = arraysize-i-1; 
		for(j=i;j<arraysize-i;j++)    
		{        
			if(array[minpos] > array[j])            
				minpos = j;    
			if(array[maxpos] < array[j])            
				maxpos = j;    
		} 
		if(i!=minpos)  
			swap(array, i, minpos);
		if(maxpos!=i)
			swap(array, arraysize-i-1, maxpos);
		else
			swap(array, arraysize-i-1, minpos);
		
#ifdef DEBUG
		printarray(array,arraysize);
#endif
	}
}
