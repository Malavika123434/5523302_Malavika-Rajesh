#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int arg1=*(const int*)a;
    int arg2=*(const int*)b;
    if (arg1<arg2) return -1;
    if (arg1>arg2) return 1;
    return 0;
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int min_unfairness = arr[k-1]-arr[0];

    for (int i=1;i<=n-k;i++) {
        int current_unfairness=arr[i+k-1]-arr[i];
        if (current_unfairness<min_unfairness) {
            min_unfairness=current_unfairness;
        }
    }

    printf("%d\n", min_unfairness);

    free(arr);
    return 0;
}
