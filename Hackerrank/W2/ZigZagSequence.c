#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findZigZagSequence(int a[], int n) {
    // Step 1: Sort the array
    qsort(a, n, sizeof(int), compare);

    // Step 2: Swap middle and last elements
    int mid = (n - 1) / 2;
    int temp = a[mid];
    a[mid] = a[n - 1];
    a[n - 1] = temp;

    // Step 3: Reverse elements after middle up to second last element
    int st = mid + 1;
    int ed = n - 2;
    while (st < ed) {
        temp = a[st];
        a[st] = a[ed];
        a[ed] = temp;
        st++;
        ed--;
    }

    // Step 4: Print the zigzag sequence
    for (int i = 0; i < n; i++) {
        printf("%d%s", a[i], (i == n - 1) ? "\n" : " ");
    }
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);
    while (test_cases--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        findZigZagSequence(a, n);
    }
    return 0;
}
