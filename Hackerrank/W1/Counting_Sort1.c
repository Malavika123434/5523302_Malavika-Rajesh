Counting Sort 1:

Code:


#include <stdio.h>
#include <string.h> 

int main() {
    int n;
    scanf("%d", &n); 

    int arr[100]; 
    memset(arr,0,sizeof(arr)); 

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d",&num); 
        arr[num]++; 
    }
    for (int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}