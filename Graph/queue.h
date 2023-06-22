#ifndef __QUEARR_H
#define __QUEARR_H
#include <assert.h>
#include "graph.h"

typedef vertex* ElementType;
typedef struct Queue* Que;

struct Queue {
    long int  NumItems;
    long int  Capacity;
    long int Front;
    long int  Rear;
    ElementType* QArr;
};



Que InitQue(long int que_capacity);
void Enque(Que Q,const ElementType E);
ElementType Deque(Que Q);



#endif