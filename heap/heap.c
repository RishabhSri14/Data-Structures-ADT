
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "heap.h"

Bool IsHeapFull(Heap H)
{
    return (H->iSize == H->iCapacity);
}

Bool IsHeapEmpty(Heap H)
{
    return (H->iSize == 0);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//////////////////////////////////////////////
// CreateHeap(size_t Capacity)
// Inputs: Max number of elements in the heap
// Outputs: Returns Pointer to a empty heap
//////////////////////////////////////////////
Heap CreateHeap(size_t Capacity)
{
    Heap H;
    // Check if Valid size
    assert(Capacity > 0);

    // Allocate memory to store Heap Data Structure
    H = (Heap)malloc(sizeof(struct stHeap));
    assert(H != NULL);

    // Allocate memory to hold the heap elements
    H->pElements = (ElementType *)malloc(sizeof(ElementType) * (Capacity));
    assert(H->pElements != NULL);

    // Initilize the Heap;
    H->iCapacity = Capacity;
    H->iSize = 0;

    return H;
}

//////////////////////////////////////////////
// Inserts the element n in to the heap H
//////////////////////////////////////////////
void InsertminHeap(Heap H, ElementType n)
{
    int i;
    if (IsHeapFull(H))
    {
        printf("\n Heap is Full\n");
        return;
    }

    if (IsHeapEmpty(H))
    {
        H->pElements[0] = n;
        H->iSize++;
        return;
    }

    for (i = H->iSize; i != 0 && H->pElements[(i - 1) / 2] > n; i = (i - 1) / 2)
    {
        swap(&(H->pElements[i]), &(H->pElements[(i - 1) / 2]));
    }

    H->pElements[i] = n;
    H->iSize++;
    return;
}

//////////////////////////////////////////////
// Builds a Heap from an array
//////////////////////////////////////////////
Heap BuildHeap(ElementType *pArray, size_t N)
{
    int i;
    Heap H;

    assert(N > 0);
    H = CreateHeap(2 * N);

    for (int i = 0; i < N; ++i)
        H->pElements[i] = pArray[i];

    H->iSize = N;
    for (i = N / 2; i >= 0; i--)
    {
        heapify(H, i);
    }

    return H;
}

//////////////////////////////////////////////
// min heapifies at index i
//////////////////////////////////////////////
void heapify(Heap H, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    int N = H->iSize;

    // If left child is larger than root
    if (l < N && H->pElements[l] < H->pElements[smallest])
        smallest = l;

    // If right child is larger than largest so far
    if (r < N && H->pElements[r] < H->pElements[smallest])
        smallest = r;

    // If largest is not root
    if (smallest != i)
    {
        swap(&(H->pElements[i]), &(H->pElements[smallest]));

        // Recursively heapify the affected sub-tree
        heapify(H, smallest);
    }
}

//////////////////////////////////////////////
// Extracts the top element of min heap
//////////////////////////////////////////////
ElementType ExtractMin(Heap H)
{
    int i, child;
    ElementType MinElement, Last;

    if (IsHeapEmpty(H))
    {
        printf("\n Heap is Empty \n");
        return H->pElements[0];
    }

    MinElement = H->pElements[0];
    Last = H->pElements[H->iSize - 1];
    H->pElements[0] = Last;
    H->iSize--;

    heapify(H, 0);

    return MinElement;
}