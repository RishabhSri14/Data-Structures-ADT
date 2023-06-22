#include <stdio.h>
#include "BinTree.h"

int main()
{
    PtrToNode root=NULL;
    PtrToNode Temp=NULL;
    int a[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    root=insert(root,a[0]);
    for(int j=1;j<n;j++)
    {
        insert(root,a[j]);
    }
    int x;
    scanf("%d",&x);
    if(search(root,x)!=NULL)
    {
        printf("Found\n");
    }
    else
    printf("Not Found\n");
    btsort(root);
    //Delete(root,a[3]);
    //if(search(root,a[3])!=NULL)
    //{
    //    printf("Found\n");
    //}
    //else
    //printf("Not Found\n");
    
}