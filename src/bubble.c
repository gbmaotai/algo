#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sort.h>

#define DEBUG



void bubblesort(int array[], int arraysize)
{
	bool flag;
	int i,j;
	printf("start bubblesort ... \n");
	if((array == NULL) || (arraysize <= 1))
		return;
	for( i=arraysize-1;i>0;i--)
	{   
		flag = true;   
		for( j=0;j<i;j++)    
              {  
                      if(array[j]>array[j+1])        
                      {           
                      	swap(array,j,j+1);          
                      	flag = false;        
				//printarray(array,arraysize);
                      }    
              }   
#ifdef DEBUG
		printarray(array,arraysize);
#endif
              if(flag)        break;
	}
}
