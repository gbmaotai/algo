#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sort.h"
#include <time.h>

#define MAXRANDOM 10000

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

int* createrandomArray(int arraysize)
{
	int* array= (int* )malloc(sizeof(int)*arraysize);
	int i;
	srand((int)time(NULL));
	for(i=0;i<arraysize;i++)
		array[i] = random()%arraysize;
	return array;
}

#define BASE 50
#define MAX_NUM 100

int* createCountrandomArray(int arraysize)
{
	int* array= (int* )malloc(sizeof(int)*arraysize);
	int i;
	srand((int)time(NULL));
	for(i=0;i<arraysize;i++)
		array[i] = (random()%MAX_NUM)+BASE;
	return array;
}

int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

void stlsort(int array[],int arraysize)
{
	qsort(array,arraysize,sizeof(int),comp);
}

bool autocheck(int size,mysort pmysort)
{
#ifdef COUNTSORT  
	int* array = createCountrandomArray(size);
#else
	int* array = createrandomArray(size);
#endif
	int* array2 = (int* )malloc(sizeof(int)*size);
	int i;

	memcpy(array2,array,sizeof(int)*size);

//	printarray(array,size);
	stlsort(array,size);
	
	pmysort(array2,size);

	for(i=0;i<size;i++)
		if(array[i]!=array2[i])
		{
			free(array);
			free(array2);
			return false;
		}	
//	printarray(array2,size);
	free(array);
	free(array2);
	return true;

}

bool checkperformance(int size,mysort pmysort)
{
	int* array = createrandomArray(size);
	int* array2 = (int* )malloc(sizeof(int)*size);
	int i;
	time_t start ,end ;
	double cost;
	memcpy(array2,array,sizeof(int)*size);

	time(&start);
	for(i=0;i<10000;i++)
	{
		memcpy(array2,array,sizeof(int)*size);
		pmysort(array2,size);
	}
	time(&end);
 	cost=difftime(end,start);

	printf("%f \n",cost);

	free(array);
	free(array2);
	return true;

}