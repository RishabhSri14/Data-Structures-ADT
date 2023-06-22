#ifndef _BINTREE_H
#define _BINTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode* PtrToNode;
typedef int ElementType;
typedef struct TreeNode Node;

struct TreeNode
{
    ElementType data;
    PtrToNode left;
    PtrToNode right;
};

Node* init_node(int data);
Node* Insert(Node* root, int data);

//1
void bstsort(PtrToNode t);


//2
void finddepth(PtrToNode T,PtrToNode P);


//3
void height(PtrToNode T);
void storedepth(PtrToNode T,PtrToNode temp,int* n,int* depth);
void calcdepth(PtrToNode T,PtrToNode P,int*c,int* flag);


//4
void isbst(PtrToNode root);
void checkbst(PtrToNode root,int* flag);


//6
void inRange(PtrToNode t,int k1,int k2);



//5
PtrToNode randomBST(int n);
int* randomArray(int n);

int Depth(PtrToNode t);
float CalcAvgDepth(int m,int n);
void avgDepth();



#endif