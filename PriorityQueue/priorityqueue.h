#ifndef _PQUE_H
#define _PQUE_H
#include "QueArr.h"

void shiftdown(ElementType* a,int i,int n);
void shiftup(ElementType* a,int i,int n);
Que InitPriorityQue(ElementType* Q,int n);
int ExtractMin(Que q);
void Update(Que q,int i,int r,int n);



#endif