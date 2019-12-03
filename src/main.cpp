#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"
#include "observer.h"
#include "link.h"

#define arraysize 15
int main()
{
//	int unsortarray[] = {56,87,56,34,97,90,6,8,1,4,9,45,80,30,9};
    int unsortarray[] = {56,50,130,100,100,149,62,56,111,79,130,60,80,130,100};
#ifdef BUBBLE
//    bubblesort(unsortarray,arraysize);
   if(autocheck(100,bubblesort))
        printf("bubblesort success \n");
    else
        printf("bubblesort failed \n");
#endif

#ifdef SELECTION
    //Selectionsort2(unsortarray,arraysize);
    if(autocheck(100,Selectionsort2))
        printf("Selectionsort2 success \n");
    else
        printf("Selectionsort2 failed \n");
    
#endif

#ifdef INSERTION
    insertionsort(unsortarray,arraysize);
/*    if(autocheck(10000,insertionsort))
        printf("insertionsort success \n");
    else
        printf("insertionsort failed \n");
*/
#endif

#ifdef SHELL
//    shellsort(unsortarray,arraysize);
    if(checkperformance(10000,shellsort))
        printf("shellsort success \n");
    else
        printf("shellsort failed \n");

#endif

#ifdef MERGE
    //mergesort(unsortarray,arraysize);
    if(checkperformance(10000,mergesort))
        printf("mergesort success \n");
    else
        printf("mergesort failed \n");

#endif

#ifdef QUICKSORT
 //   quicksort(unsortarray,arraysize);
    if(autocheck(10000,quicksort))
        printf("quicksort success \n");
    else
        printf("quicksort failed \n");

#endif

#ifdef COUNTSORT
    //countsort(unsortarray,arraysize);
    if(autocheck(10000,countsort))
        printf("countsort success \n");
    else
        printf("countsort failed \n");

#endif
//	printarray(unsortarray,arraysize);

#ifdef OBSERVER_PATTERN
    Child* oChild = new Child();
    oChild->wakeupnotifyObserver();
#endif

#ifdef TESTLINK
    testLink();
#endif
}