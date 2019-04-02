#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

#define arraysize 9
void main()
{
	int unsortarray[] = {90,87,56,34,97,2,6,8,1};
#ifdef BUBBLE
    bubblesort(unsortarray,arraysize);
#endif

#ifdef SELECTION
    Selectionsort2(unsortarray,arraysize);
#endif
	printarray(unsortarray,arraysize);

}