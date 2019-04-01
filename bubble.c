#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG
void swap(int array[],int a ,int b)
{ 
int temp = array[b];    
array[b] = array[a];    
array[a] = temp;
}

void bubblesort(int array[], int arraysize)
{
	bool flag;
	int i,j;
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

void printarray(int array[],int arraysize)
{
	int i;
	for( i=0;i<arraysize;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
void main()
{
	int unsortarray[] = {90,87,56,34,97,2,6,8,1};
	bubblesort(unsortarray,9);
	printarray(unsortarray,9);

}
