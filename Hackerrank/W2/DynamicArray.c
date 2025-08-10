#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int **sequences = (int **)malloc(n * sizeof(int *));
    int *seqSize = (int *)calloc(n, sizeof(int)); 
    int *seqCapacity = (int *)malloc(n * sizeof(int)); 

    
    for (int i = 0; i < n; i++) {
        seqCapacity[i] = 2;
        sequences[i] = (int *)malloc(seqCapacity[i] * sizeof(int));
    }

    int lastAnswer = 0;

    for (int i = 0; i < q; i++) {
        int queryType, x, y;
        scanf("%d %d %d", &queryType, &x, &y);

        
        int index = (x ^ lastAnswer) % n;

        if (queryType == 1) {
            if (seqSize[index] == seqCapacity[index]) {
                seqCapacity[index] *= 2;
                sequences[index] = (int *)realloc(sequences[index], seqCapacity[index] * sizeof(int));
            }
            sequences[index][seqSize[index]] = y;
            seqSize[index]++;
        }
        else if (queryType == 2) {
            int pos = y % seqSize[index];
            lastAnswer = sequences[index][pos];
            printf("%d\n", lastAnswer);
        }
    }

    for (int i = 0; i < n; i++) {
        free(sequences[i]);
    }
    free(sequences);
    free(seqSize);
    free(seqCapacity);

    return 0;
}
