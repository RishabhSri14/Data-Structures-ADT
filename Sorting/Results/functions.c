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

void heapify(Data a[],int i,int n, long long int*k)
{
	// Establish heap property first at a[i]
	int w = i*2 + 1; // First descendant of i (0-based indexing)
	while( w < n ) 
    {
		if ( w+1 < n )
			if ( a[w+1].a > a[w].a ) 
                w++;
        *k = *k+1;
		if ( a[i].a >= a[w].a ) 
            return;
		Data temp=a[i];
        a[i]=a[w];
        a[w]=temp;		
		i = w; // we swapped with this node ; subtree below it may need fixing
		w =i*2+1; // Get first descendant of 'i' and repeat loop procedure
	}
}

// Sorting Algorithms

void InsertionSort(Data a[],int n, long long int* k)
{
    for(int i=1;i<n;i++)
    {
        
        Data c=a[i];
        int j=i-1;
       while(j>=0)
       {
        //    if(a[j].a>c.a)
            *k =*k+1;
           if(comparator1(&a[j],&c)>0)
           {
               a[j+1]=a[j];
               j--;
           }
           else 
           break;
       }
       a[j+1]=c;

    }
}

void BubbleSort(Data a[],int n, long long int* k)
{
    int swap_count=1;
    while(swap_count!=0)
    {
        swap_count=0;
        for(int i=0;i<n-1;i++)
        {
            // if(a[i]>a[i+1])
            *k=*k+1;
            if(comparator1(&a[i],&a[i+1])>0)
            {
                Data temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap_count++;
            }
        }
    }
}

void SelectionSort(Data a[],int n, long long int* k)
{
    for (int j=n;j>0;j--)
    {
        int max=0;
        for(int i=0;i<j;i++)
        {
            // if(a[i]>a[max])
            *k=*k+1;
            if(comparator1(&a[i],&a[max])>0)
            max=i;
        }
    
        Data temp=a[max];
        a[max]=a[n-1];
        a[n-1]=temp;
    }
}


void MergeSort(Data a[],int l,int r, long long int* k)
{
    if(l>=r)
    return;
    int mid=(l+r)/2;
    MergeSort(a,l,mid,k);
    MergeSort(a,mid+1,r,k);

    Data temp [r-l+1];
    int p1=l,p2=mid+1;
    int c=0;
    while(p1<=mid && p2<=r)
    {
        // if(a[p1].a<=a[p2].a)
        *k = *k +1;
        if(comparator1(&a[p1],&a[p2])<=0)
        temp[c++]=a[p1++];
        else 
        temp[c++]=a[p2++];
    }
    while(p1<=mid)
    {
        temp[c++]=a[p1++];
    }
    while(p2<=r)
    {
        temp[c++]=a[p2++];
    }
    for(int i=l;i<=r;i++)
    a[i]=temp[i-l];
}

void HeapSort(Data a[], int n, long long int* c)
{
    for (int i = n / 2 - 1; i >= 0; i--)
 
        heapify(a, i,n,c);
 
    for (int i = n - 1; i >= 0; i--) {
 
        Data temp =a[0];
        a[0] = a[i];
        a[i] =temp;
        heapify(a, 0, i, c);
    }
}






