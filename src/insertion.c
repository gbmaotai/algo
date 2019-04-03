#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sort.h>

#define DEBUG

void insertionsort(int array[], int arraysize)
{
    int i,j;
    for(i=1;i<arraysize;i++)
    {
        for(j=i; j>0; j--)
        {
            if(array[j] < array[j-1])
                swap(array, j , j-1);
            else
                break;
        }
#ifdef DEBUG
		printarray(array,arraysize);
#endif
    }
}

void insertionsort2(int array[], int arraysize)
{
    int i,j;
    int temp;
    for(i=1;i<arraysize;i++)
    {
       temp = array[i];
        for(j=i; j>0; j--)
        {
 
            if(temp < array[j-1])
                array[j] = array[j-1];
            else
            {
                break;
            }    
        }
        array[j] = temp;
#ifdef DEBUG
		printarray(array,arraysize);
#endif
    }
}