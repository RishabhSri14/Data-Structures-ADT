#include <stdio.h>
#include <stdlib.h>
typedef struct edge Edge;



struct edge
{
    int id;//1 for air -1 for water
    int s;
    int d;
    long long int l;
};

int findRoot(int a[],int i)
{
    if(a[i]==i)
    return i;
    return findRoot(a,a[i]);
}

void MergeSort(Edge* e,int l,int r)//Sorting after dividing
{
    if(l>=r)
    return;
    int mid=(l+r)/2;
    MergeSort(e,l,mid);
    MergeSort(e,mid+1,r);

    Edge temp [r-l+1];
    int p1=l,p2=mid+1;
    int c=0;
    while(p1<=mid && p2<=r)
    {
        if(e[p1].l<=e[p2].l)
        temp[c++]=e[p1++];
        else if(e[p1].l>e[p2].l)
        temp[c++]=e[p2++];
    }
    while(p1<=mid)
    {
        temp[c++]=e[p1++];
    }
    while(p2<=r)
    {
        temp[c++]=e[p2++];
    }
    for(int i=l;i<=r;i++)
        e[i]=temp[i-l];
}
void Assign(int parent[],int rank[],int r1,int r2) //Modification done in comment
{
    if (rank[r1] < rank[r2])
        parent[r1] = r2;    // parent[r1] = findRoot(r2)
    else if (rank[r2] < rank[r1])
        parent[r2] = r1;    // parent[r2] = findRoot(r1)
    else
        parent[r1]=r2;      // parent[r1]= findRoot(r2)
        rank[r2]++;
}


int main()
{
    Edge* e;
    Edge* o;
    int n,a;
    scanf("%d %d",&n,&a);
    e=malloc(sizeof(Edge)*(a));
    o=malloc(sizeof(Edge)*n-1);
    for(int i=0;i<a;i++)
    {
        e[i].id=1;
        scanf("%d %d %lld",&e[i].s,&e[i].d,&e[i].l);
    }
    MergeSort(e,0,a-1);
    int parent[n+1];
    int rank[n+1];
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
    int c=0;
    int curr_ind=0;
    while(c<n-1 && curr_ind<a)
    {
        Edge curr_edge=e[curr_ind++];
        int r1=findRoot(parent,curr_edge.s);
        int r2=findRoot(parent,curr_edge.d);
        if(r1!=r2)
        {
            o[c++]=curr_edge;
            //parent[r2]=r1;
            Assign(parent,rank,r1,r2);
        }
    }
    long long int s=0;
    for(int i=0;i<n-1;i++)
    {
        s+=o[i].l;
    }
    printf("%lld",s);
    

}
