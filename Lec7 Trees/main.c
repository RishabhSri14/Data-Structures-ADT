#include <stdio.h>
#include "GenTrees.h"
int main()
{
    PtrToNode root=InitNode('A');
    root->child=InitNode('B');
    root->child->sibling=InitNode('C');
    root->child->sibling->sibling=InitNode('D');
    root->child->child=InitNode('E');
    root->child->child->sibling=InitNode('F');
    root->child->sibling->child=InitNode('G');
    root->child->sibling->child->child=InitNode('H');
    root->child->sibling->sibling->child=InitNode('I');
    root->child->sibling->sibling->child->child=InitNode('J');
    root->child->sibling->sibling->child->child->sibling=InitNode('K');
    PrintPre(root);
    printf("\n");
//    PrintPre2(root);
//    printf("\n");
    PrintPost(root);
    printf("\n");
    PrintLevel(root);
}