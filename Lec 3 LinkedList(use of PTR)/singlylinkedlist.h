#ifndef __SLL_H
#define __SLL_H

typedef int ElementType;


int AreEqualElems(int a,int b); 

typedef struct Node ListNode;
typedef struct Node* PtrToNode;

typedef PtrToNode List;
typedef PtrToNode Position;

struct Node {
    ElementType Element;
    Position Next;
};

// Creates a node and instantiates the element
// Returns pointer to created node
PtrToNode MakeNode(ElementType X);

List CreateEmptyList(); // Creates an empty list returning header node
void CreateEmptyList1(List* PP); // Creates an empty list with pointer to header node PP
void CreateEmptyList2(List PP); // Does not work as intended(Creates an empty list with pointer to header node PP)

void InsertAtFront(List* h,ElementType X);
void InsertAtFront_v2(List L,ElementType X); //TODO: Simpler - can have this version if we use header-based linked lists
void InsertAtRear(List* LP,ElementType X); // TODO

void DeleteNode(PtrToNode P);
void DeleteList(List* LP); // TODO
void EmptyList(List* LP); // TODO

void PrintList(List P); // TODO

#endif