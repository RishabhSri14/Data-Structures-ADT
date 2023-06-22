#ifndef _GENTREES_H
#define _GENTREES_H

typedef char ElementType ;
typedef struct node Node;
typedef Node* PtrToNode;
typedef struct Queue* Queue;


struct node{
    ElementType data;
    PtrToNode child;
    PtrToNode sibling;
};

struct Queue
{
    PtrToNode* a;
    int lid;
    int rid;
};


void Enque(PtrToNode n,Queue q);
void SibEnque(PtrToNode root,Queue q);
PtrToNode Deque(Queue q);

PtrToNode InitNode(ElementType a);
void PrintPre(PtrToNode root);
void PrintPre2(PtrToNode root);
void PrintPost(PtrToNode root);
void PrintLevel(PtrToNode root);
#endif