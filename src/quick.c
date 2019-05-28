#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sort.h>

int partition(int array[],int left, int right)
{
    int pivot = left;
    int lastsmall = left+1;
    for(int i=lastsmall;i<=right;i++){
        if(array[i] < array[pivot]){
            swap(array,i,lastsmall);
            lastsmall++;
            printarray(array,15);
        }
    }
    swap(array,pivot,lastsmall-1);
 //   printarray(array,15);
//    printf("round \n");
    return lastsmall-1;
}

int partition1(int array[],int left, int right)
{
    int pivot = right;
    int smallindex = left;
    int largeindex = right - 1;
    while(smallindex < largeindex ){
        while(array[smallindex] < array[pivot]) smallindex++;
        while(array[largeindex] > array[pivot]) largeindex--;
        if(smallindex<largeindex) 
        {
            swap(array,smallindex,largeindex);
            smallindex++;
            largeindex--;
        }    
  //      printarray(array,15);
    }
    if(smallindex == pivot)
        return smallindex;
    if(array[smallindex] > array[pivot])
    {
        swap(array,pivot,smallindex);
    //    printf("round %d %d\n",smallindex,array[smallindex]);
     //   printarray(array,15);
        return smallindex;
    }
    else{
        swap(array,pivot,smallindex+1);
    //    printf("round %d %d\n",smallindex+1,array[smallindex+1]);
    //    printarray(array,15);
        return smallindex+1;
    }

}

void recursionquick(int array[],int left, int right)
{
    int pivot;
//    printarray(array,15);
    if(left < right){
        pivot = partition1(array,left,right);
        if(left < pivot-1) recursionquick(array,left,pivot-1);
        if(pivot+1 < right) recursionquick(array,pivot+1,right);
    }
}

void quicksort(int array[], int arraysize)
{
//int unsortarray[] = {2,5,6,7,9,1,3,4,8,10};
//merge(unsortarray,0,5,9);
//    printarray(array,arraysize);
    recursionquick(array,0,arraysize-1);
#ifdef DEBUG
//		printarray(array,arraysize);
#endif
}
