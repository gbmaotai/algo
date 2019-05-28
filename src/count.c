#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sort.h>

#define DEBUG

//50 -- 150
#define BASE 50
#define MAX_NUM 100

void countsort(int array[], int arraysize)
{
    int* arraysort = calloc(arraysize,sizeof(int)  );
    int* arraycount = calloc(MAX_NUM,sizeof(int)  );
    int index;
     for(int i=0;i<MAX_NUM;i++)
        arraycount[i] = 0;
    //count
    for(int i=0;i<arraysize;i++){
        index = array[i];
        if((index<BASE)||(index>BASE+MAX_NUM-1))
        {
            printf("wrong source out of range \n");
            continue;
        }
        arraycount[index-BASE]++;
    }
    for(int i=1;i<MAX_NUM;i++){
        arraycount[i] = arraycount[i] + arraycount[i-1];
    }
//    printarray(arraycount,MAX_NUM);
    for(int i=arraysize-1;i>=0;i--){
        arraycount[array[i]-BASE]--;
        arraysort[arraycount[array[i]-BASE]] = array[i];
    }
#ifdef DEBUG
		printarray(arraysort,arraysize);
#endif
    for(int i=0;i<arraysize;i++)
        array[i] = arraysort[i];
}