#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "singlylinkedlist.h"


int AreEqualElems(int a,int b)
{
    if (a==b)
    return 1;
    else
    return 0;
}


PtrToNode MakeNode(ElementType X)
{
    PtrToNode a=(PtrToNode)malloc(sizeof(ListNode));
    assert (a!=NULL);
    a->Element=X;
    a->Next=NULL;
    return a;
}

//DIFFERENT CASES TO CREATE HEADER FILES
List CreateEmptyList()  //Easiest
{
    List p;
    p=MakeNode(0);
    return p;
}
//                   (IMPORTANT)
//when we wish to change the address to which a pointer points by function call

// without function call it's just a matter of assignment 
void CreateEmptyList1(List* PP)  //Second use of double pointer after arrays(RECOMMENDED)
{
    *PP=MakeNode(0);

}
/*used as

struct node h;
PtrToNode p;
p=&h;
CreateEmptyList1(&p);

*/

//in this case address of the variable remains same as it was before sending but the value of node changes
void CreateEmptyList2(List PP)//wrong method when we want to change the address as well
{
    PP=MakeNode(0);
}

//Hint: When we want changes in any thing in a function reflect in other function we pass it as &(the thing)
/*
The thing                        in parameter                   in parameter
                              (function_prototype)         (during_function_call)
           
variable a                           *a                                   p=&a
address of variable a                **a                                pp=&p=&(&(a))


think by &a or &(&(a))->remove one &->any change to the remaining in one function will reflect in other function
*/ 



//makes new node as head
void InsertAtFront(List* h,ElementType X)
{
    PtrToNode p=MakeNode(X);
    p->Next=*h;
    *h=p;
}

void InsertAtFront_v2(List L,ElementType X)
{
    PtrToNode p=MakeNode(X);
    p->Next=L;
    ListNode temp=*p;
    *p=*L;
    *L=temp;
}

void InsertAtRear(List* LP,ElementType X)
{
    PtrToNode p=MakeNode(X);
    PtrToNode temp=*LP;
    while ((temp->Next)!=NULL)
    {
        temp=temp->Next;
    }
    temp->Next=p;
}

void DeleteNode(PtrToNode P)
{
    if (P!=NULL)
    free(P);
}
void DeleteList(List* LP)//Leaving head node
{
    (*LP)->Next=NULL;
}

void EmptyList(List* LP)
{
    free(*LP);
}
//                            (IMPORTANT)
//We can use temp  and assign it to the pointer ,thinking that changing temp will change LP.
//as the original thing that matters is the address 

void PrintList(List P)
{
    while((P->Next)!=NULL)
    {
        printf("%d\n",P->Element);
        P=P->Next;
    }
}

void ReverseLinkedList(PtrToNode P)
{
    
}

