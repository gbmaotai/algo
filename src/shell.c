#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sort.h>

#define DEBUG

void shellsort(int array[], int arraysize)
{
    //D.shell , enhanced insertion sort
    //jump gap

    int i,j,gap;
    for(gap = arraysize/2; gap>0;gap/=2)
    {
        for(i=gap; i<arraysize;i++)
        {
            for(j=i;j>gap-1;j-=gap)
                if(array[j] < array[j-gap])
                    swap(array, j ,j-gap);
                else 
                    break;
        }
#ifdef DEBUG
		//printarray(array,arraysize);
#endif
    }
}

void shellsort2(int array[], int arraysize)
{
    //D.shell , enhanced insertion sort
    //jump gap
    int i,j,gap,h=0;
    while(h < arraysize)
    {
        h = 3*h + 1;
    }

    for(gap = h; gap>0;gap=(gap-1)/3)
    {
        for(i=gap; i<arraysize;i++)
        {
            for(j=i;j>gap-1;j-=gap)
                if(array[j] < array[j-gap])
                    swap(array, j ,j-gap);
                else 
                    break;
        }
#ifdef DEBUG
        //printf("%d\n",gap);
		//printarray(array,arraysize);
#endif
    }
}