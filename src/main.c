#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

#define arraysize 9
void main()
{
//	int unsortarray[] = {90,87,56,34,97,2,6,8,1};
    
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
//	printarray(unsortarray,arraysize);

}