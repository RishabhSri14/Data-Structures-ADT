#include <stdio.h>

void InsertionSort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        
        int c=a[i];//c is imp everywhere it's used
        int j=i-1;
        /*Correct code but not insertion sort
        while(j>=0)
        {
            if(a[j]>a[c])
            {
                int temp=a[c];
                a[c]=a[j];
                a[j]=temp;
                c=j;
                j--;
                
            }
            else
            break;
        }
        */
       while(j>=0)
       {
           if(a[j]>c)
           {
               a[j+1]=a[j];
               j--;
           }
           else 
           break;
       }
       a[j+1]=c;

    }
}

//O(n^2)
void BubbleSort(int a[],int n)
{
    int swap_count=1;
    while(swap_count!=0)
    {
        swap_count=0;
        for(int i=0;i<n;i++)
        {
            if(a[i+1]<a[i])
            {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap_count++;
            }
        }
    }
}

//O(n^2)
void SelectionSort(int a[],int n)
{
    if(n==1)
    return ;
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>a[max])
        max=i;
    }
    int temp=a[max];
    a[max]=a[n-1];
    a[n-1]=temp;
    SelectionSort(a,n-1);
}


//Best case is O(nlogn)  but average case is O(n^2)
void QuickSort(int a[],int l,int r)//Sorting before dividing
{
    if(l>=r)
    return;

/* NO USE as it is not reducing space complexity
    int pivot =a[r];
    int s=0,lc=0;
    int small[1000],large[1000],temp[10000];
    for(int i=l;i<r;i++)
    {
        if(a[i]<pivot)
        {
            small[s++]=a[i];
        }
        if(a[i]>pivot)
        {
            large[lc++]=a[i];
        }
    }
    for(int i=0;i<s;i++)
    temp[i]=small[i];

    temp[s]=pivot;

    for(int i=0;i<lc;i++)
    temp[i+s+1]=large[i];

    for(int i=l;i<=r;i++)
    a[i]=temp[i-l];

    */

    int pivot = a[r];
    int part=l;//Consider lth position to be the desired position such that no elements behind it
    for(int j=l;j<r;j++)
    {
        if(a[j]<pivot)//we encountered an element  that should be  behind the part
        {
            
            int temp=a[part];// move that element to the left section of part
            a[part]=a[j];
            a[j]=temp;
            part++;// new position of part
        }
        int temp=a[r];
        a[r]=a[part];
        a[part]=temp;

    }


    /*int p1=l,p2=r;
    while(p1<p2)
    {
        while(a[p1]<a[l])
        {
            p1++;
        }
        
        while(a[p2]>a[l])
        {
            p2--;
        }
        int temp=a[p1];
        a[p1]=a[p2];
        a[p2]=temp;

    }
    int temp=a[l];
    a[l]=a[p2];
    a[p2]=a[l];*/

    QuickSort(a,l,part-1);
    QuickSort(a,part+1,r);
}

//O(nlogn)
void MergeSort(int a[],int l,int r)//Sorting after dividing
{
    if(l>=r)
    return;
    int mid=(l+r)/2;
    MergeSort(a,l,mid);
    MergeSort(a,mid+1,r);

    int temp [r-l+1];
    int p1=l,p2=mid+1;
    int c=0;
    while(p1<=mid && p2<=r)
    {
        if(a[p1]<=a[p2])
        temp[c++]=a[p1++];
        else if(a[p1]>a[p2])
        temp[c++]=a[p2++];
    }
    while(p1<=mid)
    {
        temp[c++]=a[p1++];
    }
    while(p2<=r)
    {
        temp[c++]=a[p2++];
    }
    for(int i=l;i<=r;i++)
    a[i]=temp[i-l];
}


int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    InsertionSort(a,n);
    printf("Sorted Array:\n");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}   
