#include "defs.h"



//helper functions

int comparator1(const void *a, const void *b) {
    DataPtr da = (DataPtr) a;
    DataPtr db = (DataPtr) b;
    return (da->a - db->a);//asc
    // return (db->a - da->a);//desc
}

// function to print the list
void printList(DataPtr list, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, %f, %s\n", list[i].a, list[i].b, list[i].c);
    }
}

void heapify(Data a[],int i,int n)
{
	int w = i*2 + 1; 
	while( w < n ) 
    {
		if ( w+1 < n )
			if ( a[w+1].a > a[w].a ) 
                w++;
		if ( a[i].a >= a[w].a ) 
            return;
		Data temp=a[i];
        a[i]=a[w];
        a[w]=temp;		
		i = w; 
		w =i*2+1; 
	}
}

// Sorting Algorithms

void InsertionSort(Data a[],int n)
{
    // Your code goes here
}

void BubbleSort(Data a[],int n)
{
    // Your code goes here
}

void SelectionSort(Data a[],int n)
{
    // Your code goes here
}


void MergeSort(Data a[],int l,int r)
{
    // Your code goes here
}

void HeapSort(Data a[], int n)
{
    // Your code goes here
}






