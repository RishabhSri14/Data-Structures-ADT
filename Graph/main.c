#include "graph.h"
#include "queue.h"
//implementation of queue
Que InitQue(long int que_capacity)
{
    Que Q = (Que)malloc(sizeof(struct Queue));
    assert(Q != NULL);

    assert(que_capacity > 0);
    Q->Capacity = que_capacity;

    Q->QArr = (ElementType*)malloc(Q->Capacity * sizeof(ElementType));
    assert (Q->QArr != NULL);

    Q->NumItems = 0;
    Q->Rear = -1;
    Q->Front = 0;    
}

void Enque(Que Q,const ElementType E)
{

    Q->Rear = (Q->Rear + 1)%(Q->Capacity);
    Q->QArr[Q->Rear] = E;
    ++(Q->NumItems);
}

ElementType Deque(Que Q)
{
    ElementType E = Q->QArr[Q->Front];
    Q->Front = (Q->Front +1) % Q->Capacity;
    --(Q->NumItems);

    return E;
}





int main()
{
    int v,e;
    printf("Enter the no. of vertices:\n");
    scanf("%d",&v);
    Adj_list Adj_List=InitAdj_List(v);
    printf("Enter the no. of edges:\n");
    scanf("%d",&e);
    int E[e][3];
    printf("Considering the vertices as number 0,1,2,3,...\n");
    printf("Enter the pairs of vertices whose has an edge\n");
    int **Adj_Matrix=InitAdj_Mat(v);

    for(int i=0;i<e;i++)
    {   
        scanf("%d %d %d",&E[i][0],&E[i][1],&E[i][2]);
        UpdateAdj_Mat(Adj_Matrix,E[i][0],E[i][1],E[i][2]);
        InsertEdge(E[i][0],E[i][1],Adj_List);
        InsertEdge(E[i][1],E[i][0],Adj_List);
    }  
    printf("The nodes in breadth first order are:\n");
    BFS_List(Adj_List,v);
    //BFS_Mat(Adj_Matrix,v);
    PtrTovertex finishTime[v];
    printf("The nodes in depth first order are:\n");
    DFS_List(Adj_List,v,0,finishTime);
    printf("Edges Sorted in finish time are\n");
    for(int i=0;i<v;i++)
    {
        printf("%d ",(finishTime[i])->id);
    }
    printf("\n");

    //DFS_Mat(Adj_Matrix,v,0);
    printf("The shortest path between 0 and each node is:\n");
    Djishtra(Adj_List.list,Adj_Matrix,v);
    BellmondFord(Adj_List.list,Adj_Matrix,v);
    printf("The MST of above graph is: \n");
    Prims(Adj_List.list,Adj_Matrix,v);

}


