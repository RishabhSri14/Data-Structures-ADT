#include "QueArr.h"
#include <stdio.h>
#include <assert.h>

Que InitQue(long int que_capacity)
{
    Que Q = (Que)malloc(sizeof(struct Queue));
    assert(Q != NULL);

    assert(que_capacity > 0);
    Q->Capacity = que_capacity;

    Q->QArr = (ElementType*)malloc(Q->Capacity * sizeof(ElementType));
    assert (Q->QArr != NULL);

    Q->NumItems = 0;
    Q->Rear = -1; // or -1
    Q->Front = 0;    
}

void Enque(Que Q,const ElementType E)
{
    assert(!IsFull(Q));

    Q->Rear = (Q->Rear + 1)%(Q->Capacity);
    Q->QArr[Q->Rear] = E;
    ++(Q->NumItems);
}

ElementType Deque(Que Q)
{
    assert(!IsEmpty(Q));

    ElementType E = Q->QArr[Q->Front];
    Q->Front = (Q->Front +1) % Q->Capacity;
    --(Q->NumItems);

    return E;
}

int IsEmpty(const Que Q)
{
    return (Q->NumItems == 0);
}

int IsFull(const Que Q)
{
    return (Q->NumItems == Q->Capacity);
}

void ClearQueue(Que Q)
{
    Q->NumItems = 0;
    Q->Rear = Q->Capacity-1;
    Q->Front = 0;    
}

void DeleteQue(Que* QP)
{
    Que Q = NULL;
    if(*QP)
    {
        Q = *QP;
        free(Q->QArr);
        free(Q);
        *QP = NULL;
    }
}

void PrintQue(const Que Q)
{
    assert(Q->NumItems > 0);

    // Print from front to rear
    long unsigned int idx = Q->Front;
    while(1)
    {
        printf("[%d] ",Q->QArr[idx]);
        if(idx == Q->Rear)
            break;
        else
            idx = (idx +1)% Q->Capacity;
    }
     
    printf("\n");

}


//Priority

void shiftdown(ElementType* a,int i,int n)
{
	// Establish heap property first at a[i]
	int w = i*2 + 1; // First descendant of i (0-based indexing)
	while( w < n ) 
    {
		if ( w+1 < n )
			if ( a[w+1] < a[w] ) 
                w++;
		if ( a[i] <= a[w] ) 
            return;
		ElementType temp=a[i];
        a[i]=a[w];
        a[w]=a[i];		
		i = w; // we swapped with this node ; subtree below it may need fixing
		w =i*2+1; // Get first descendant of 'i' and repeat loop procedure
	}
}


void shiftup(ElementType* a,int i,int n)
{
    int p=(i-1)/2;
    while(p>=0)
    {
        if(i%2==0 )
            if(i-1>=0 && a[i]>=a[i-1])
                i--;
        if(i%2!=0 )
            if(i+1<n && a[i]>=a[i+1])
                i++;
        if(a[p]<=a[i])
            return;
        ElementType temp=a[p];
        a[p]=a[i];
        a[i]=temp;
        i=p;
        p=(i-1)/2;
    }
}



Que InitPriorityQue(ElementType* q,int n)
{
    Que Q=InitQue(1e10);
    for(int i=0;i<n;i++)
    {
        Enque(Q,q[i]);
    }
    for(int i=Q->Front+n/2-1;i>=Q->Front;i--)
    {
        shiftdown(Q->QArr,i,Q->NumItems);
    }
    return Q;

}

int ExtractMin(Que q)
{
    ElementType min=q->QArr[q->Front];
    q->QArr[q->Front]=q->QArr[q->Rear];
    q->QArr[q->Rear]=min;
    Deque(q);
    shiftdown(q->QArr,0,q->NumItems);
    return min;
}

void Update(Que q,int i,int r)
{
    int n=q->NumItems;
    q->QArr[i]=r;
    ElementType* a = q->QArr;
    shiftup(q->QArr,i,n);
    shiftdown(q->QArr,i,n);            
}

