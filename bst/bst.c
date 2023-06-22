#include "bst.h"

Node* init_node(int data){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* Insert(Node* root, int data){
    if(root == NULL) return init_node(data);
    if(data < root->data) root->left = Insert(root->left, data);
    else root->right = Insert(root->right, data);
    return root;
}

void bstsort(PtrToNode t)
{
    if(t==NULL)
    return;
    bstsort(t->left);
    printf("%d ",t->data);
    bstsort(t->right);
}





void finddepth(PtrToNode T,PtrToNode P)
{
    int c=0,flag=0;
    calcdepth(T,P,&c,&flag);
    printf("%d\n",c);
}






void calcdepth(PtrToNode root,PtrToNode P,int*c,int*flag)
{
    if(root==NULL)
    {
        (*c)--;
        return;
    }
    if(root == P)
    {
        *flag=1;
        return;
    }
    (*c)++;
    calcdepth(root->left,P,c,flag);
    if(*flag==0)
    {
        (*c)++;
        calcdepth(root->right,P,c,flag);
    }
    if(*flag==0)
    (*c)--;
}

void storedepth(PtrToNode T,PtrToNode temp,int* n,int* depth)
{
    if(temp== NULL)
    return;

    if(temp!=NULL)
    {
        int c=0,flag=0;
        calcdepth(T,temp,&c,&flag);
        depth[*n]=c;
        (*n)++;
    }
    storedepth(T,temp->left,n,depth);
    storedepth(T,temp->right,n,depth);
}

void height(PtrToNode T)
{
    int depth[10000];
    int n=0;
    storedepth(T,T,&n,depth);
    int depth_max=depth[0];
    for(int i=0;i<n;i++)
    {
        if(depth[i]>depth_max)
        depth_max=depth[i];
    }
    printf("%d\n",depth_max);
}






void checkbst(PtrToNode root,int* flag)
{
    if(root==NULL)
    return;
    if(root->left !=NULL && root->left->data > root->data )
    *flag=0;
    if(root->right!=NULL && root->right->data < root->data)
    *flag=0;
    checkbst(root->left,flag);
    checkbst(root->right,flag);
}


void isbst(PtrToNode root)
{
    int c=1;
    checkbst(root,&c);
    printf("%d\n",c);
}







void inRange(PtrToNode t,int k1,int k2)
{
    if(t==NULL)
    return;
    inRange(t->left,k1,k2);
    if(t->data>=k1 && t->data<=k2)
    printf("%d ",t->data);
    inRange(t->right,k1,k2);
}





int* randomArray(int n)
{
    int* a=(int*)malloc(n*sizeof(int));
    int temp;
    int i,j;
    srand(time(0));
    for(i=0;i<n;i++)
    {
        temp=1+rand()%n;
        for(j=0;j<i;j++)
        {
            if(temp == a[j])
            break;
        }
        if(j!=i)
        {
            i--;
        }
        else
        a[i]=temp;
    }
    return a;
}

PtrToNode randomBST(int n)
{
    PtrToNode root=NULL;
    int *a;
    a=randomArray(n);
    for(int i=0;i<n;i++)
    {
        root=Insert(root,a[i]);
    }
    return root;
}

int Depth(PtrToNode T)
{
    int depth[10000];
    int n=0;
    storedepth(T,T,&n,depth);
    int depth_max=depth[0];
    for(int i=0;i<n;i++)
    {
        if(depth[i]>depth_max)
        depth_max=depth[i];
    }
    return depth_max;
}

float CalcAvgDepth(int m,int n)
{
    PtrToNode root;
     float s=0;
    for(int i=0;i<m;i++)
    {
        root=randomBST(n);
        s+=Depth(root);
    }
    return (s/m);
}

void avgDepth()
{
    int M[4]={10,50,100,1000};
    int N[4]={10,50,100,1000};
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            float temp=CalcAvgDepth(M[i],N[j]);
            printf("%lf ",temp);
        }
        printf("\n");
    }
}
