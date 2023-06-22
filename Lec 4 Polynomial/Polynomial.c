#include <stdio.h>
#include  "Polynomial.h"
#include <stdlib.h>
#include <stdbool.h>

Poly InitPoly()
{
    Poly p=(Poly)(malloc(sizeof(PTerm)));
    p->Next=NULL;
    return p;
}
// Assuming the exponents are arrange in increasing order
void AddTerm(Poly P,double coefficient,unsigned long int exponent)
{
    Poly temp=(Poly)malloc(sizeof(PTerm));
    assert(temp!=NULL);
    temp->expo=exponent;
    temp->coeff=coefficient;
    temp->Next=NULL;
    Poly Pi=P;
    while((P->expo)<=exponent && P->Next!=NULL)
    {
        Pi=P;
        P=P->Next;
    }
    if((Pi->expo)==exponent)
    {
        Pi->coeff+=coefficient;
    }
    if(Pi->expo!=exponent)
    {
        Pi->Next=temp;
        temp->Next=P;
    }
}

void DeleteTerm(Poly P,unsigned long int exponent)
{
    bool flag=false;
    Poly Pi=P;
    while((P->expo)!=exponent && P->Next!=NULL)
    {
        Pi=P;
        P=P->Next;
        flag=true;
    }
    if(flag==false)
    return;
    Pi->Next=P->Next;
}

void UpdateTerm(Poly P,double new_coefficient,unsigned long int exponent)
{
    bool flag=false;
    while((P->expo)!=exponent && P->Next!=NULL)
    {
        P=P->Next;
        flag=true;
    }
    if(flag==false)
    return;
    P->coeff=new_coefficient;
}