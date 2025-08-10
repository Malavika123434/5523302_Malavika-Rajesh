#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare_chars(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}
char* gridChallenge(int gridSize, char** grid) {
    for (int i = 0; i < gridSize; i++) {
        qsort(grid[i], strlen(grid[i]), sizeof(char), compare_chars);
    }
    int colCount = strlen(grid[0]);
    for (int j = 0; j < colCount; j++) {
        for (int i = 0; i < gridSize - 1; i++) {
            if (grid[i][j] > grid[i+1][j]) {
                return "NO";
            }
        }
    }
    return "YES";
}

int main() {
    int t;
    scanf("%d", &t); 

    while (t--) {
        int n;
        scanf("%d", &n);
        char **grid = malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++) {
            grid[i] = malloc(101 * sizeof(char)); 
            scanf("%s", grid[i]);
        }
        printf("%s\n", gridChallenge(n, grid));
        for (int i = 0; i < n; i++) {
            free(grid[i]);
        }
        free(grid);
    }
    return 0;
}
