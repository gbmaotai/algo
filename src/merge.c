#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sort.h>

#define DEBUG

void merge(int array[], int leftpos, int rightpos, int lastpos)
{
    int* temparray = (int* )malloc(sizeof(int)*(lastpos - leftpos + 1));
    int i = leftpos;
    int j = rightpos;
    int k = 0;
    while((i<rightpos)&&(j<=lastpos)  ){
        if(array[i] <= array[j])
            temparray[k++] = array[i++];
        else
            temparray[k++] = array[j++];
    }
    while(i<rightpos)
        temparray[k++] = array[i++];
    while(j<=lastpos)
        temparray[k++] = array[j++];    
    
    for(i=0;i<=lastpos-leftpos;i++)
    {
        array[leftpos+i] = temparray[i]; 
    }
    free(temparray);
}

void recursionmerge(int array[],int left, int right)
{
    if(left == right ) 
        return;
    int mid = (right+left)/2;

    recursionmerge(array,left,mid);
    recursionmerge(array,mid+1,right);
    merge(array,left,mid+1,right);
//    printarray(array,15);
}
void mergesort(int array[], int arraysize)
{
//int unsortarray[] = {2,5,6,7,9,1,3,4,8,10};
//merge(unsortarray,0,5,9);
//    printarray(array,arraysize);
    recursionmerge(array,0,arraysize-1);
#ifdef DEBUG
//		printarray(array,arraysize);
#endif
}

