#ifdef __cplusplus 
extern "C" { 
#endif

typedef void (*mysort)(int array[], int arraysize);
void swap(int array[],int a ,int b);
void printarray(int array[],int arraysize);
void bubblesort(int array[], int arraysize);
void Selectionsort(int array[], int arraysize);
void Selectionsort2(int array[], int arraysize);
void insertionsort(int array[], int arraysize);
void shellsort(int array[], int arraysize);
void shellsort2(int array[], int arraysize);
void mergesort(int array[], int arraysize);
void quicksort(int array[], int arraysize);
void countsort(int array[], int arraysize);
bool autocheck(int size,mysort pmysort);
bool checkperformance(int size,mysort pmysort);

#ifdef __cplusplus 
} 
#endif 