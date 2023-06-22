#ifndef __QUEARR_H
#define __QUEARR_H


typedef int ElementType;
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

int IsEmpty(const Que Q);
int IsFull(const Que Q);

void PrintQue(const Que Q);

void ClearQue(Que Q);
void DeleteQue(Que* Q);



#endif
