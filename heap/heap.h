#ifndef __HEAP_H
#define __HEAP_H

// Implementation for minHeap

#include <stdlib.h>
#include <limits.h>

typedef struct stHeap *Heap;
typedef int ElementType;
typedef unsigned int Position;
typedef unsigned int Bool;

struct stHeap
{
    // Number of elements in the heap
    int iSize;
    int iCapacity;
    /* data */
    ElementType *pElements;
    // Elements are stored from 0, 1, 2...,iSize - 1;
};

Heap CreateHeap(size_t Capacity);                   // Creates an empty min heap
void InsertminHeap(Heap H, ElementType n);          // Inserts into an element into a min heap
ElementType ExtractMin(Heap H);                     // Extracts the minimum element of the heap and 
                                                    // maintains the heap property
Heap BuildHeap(ElementType *pArray, size_t N);      // Builds a heap using an array
void heapify(Heap H, int i);                        // Heapifies a min heap at index i
Bool IsHeapFull(Heap H);                            // Checks in heap is full or not
Bool IsHeapEmpty(Heap H);                           // Checks if heap is empty or not

#endif