#ifndef _BINTREE_H
#define _BINTREE_H

typedef struct TreeNode* PtrToNode;
typedef int ElementType;

struct TreeNode
{
    ElementType data;
    PtrToNode Left;
    PtrToNode Right;
};

PtrToNode InitNode(ElementType data);
PtrToNode prevsearch(PtrToNode root,ElementType data);
PtrToNode SearchSmallest(PtrToNode root);


//Basics of binary search tree
PtrToNode insert(PtrToNode root,ElementType data);
PtrToNode search(PtrToNode root,ElementType data);
PtrToNode Delete(PtrToNode root,ElementType data);
void btsort(PtrToNode t);


void finddepth(PtrToNode T,PtrToNode P);



#endif