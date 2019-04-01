#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int array[],int a ,int b)
{ 
int temp = array[b];    
array[b] = array[a];    
array[a] = temp;
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