#include "defs.h"


int main() {

    srand(time(NULL));

    clock_t start, end;
    double execution_time;

    int tc; 

    scanf("%d", &tc);

    while(tc--) {
        int n;
        scanf("%d", &n);

        Data list[n];

        for(int i = 0; i < n; i++) {
            scanf("%d", &list[i].a);
            scanf("%f", &list[i].b);
            scanf("%s", list[i].c);
        }
        start = clock();
        long long int c =0;
        qsort(list, n, sizeof(Data), comparator1);
        // SelectionSort(list,n,&c);
        // InsertionSort(list,n,&c);
        // BubbleSort(list,n,&c);
        // MergeSort(list,0,n-1,&c);
        // HeapSort(list,n,&c);
        end = clock();

        execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
        printf("Number of comparisons for %d elements: %lld\n", n, c);

        // printf("\nSorted list:\n");
        // printList(list, n);

    }
}