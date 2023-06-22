#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct vertex vertex;

typedef  struct vertex* PtrTovertex;
struct vertex
{
    int id;
    PtrTovertex next;
};

typedef struct Adj_list
{
    PtrTovertex* list;
}Adj_list;






PtrTovertex InitNode(int data);
int** InitAdj_Mat(int v) ;
void UpdateAdj_Mat(int** a,int i,int j,int weight);
Adj_list InitAdj_List(int v);
void InsertEdge(int u,int v,Adj_list a);// directed u->v
void BFS_List(Adj_list  a,int n);
void BFS_Mat(int ** a,int n);
void DFS_List(Adj_list a,int n,int start_node,PtrTovertex ft[]);
void DFS_visit(Adj_list a,PtrTovertex start,int* c,int check[],PtrTovertex ft[]);
void Djishtra(PtrTovertex* a,int ** b,int n);
void Prims(PtrTovertex* a,int **b,int n);
void BellmondFord(PtrTovertex* a,int **b,int n);

#endif