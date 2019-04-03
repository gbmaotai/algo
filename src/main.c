#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

#define arraysize 15
void main()
{
	int unsortarray[] = {90,87,56,34,97,56,6,8,1,4,9,45,80,30,9};
    
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
//	printarray(unsortarray,arraysize);

}