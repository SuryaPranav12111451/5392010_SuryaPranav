#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 105

// Compare function for qsort
int cmp_char(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char grid[MAX][MAX];

        // Read and sort each row
        for (int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
            qsort(grid[i], n, sizeof(char), cmp_char);
        }

        int valid = 1;
        // Check all columns
        for (int col = 0; col < n && valid; col++) {
            for (int row = 1; row < n; row++) {
                if (grid[row][col] < grid[row-1][col]) {
                    valid = 0;
                    break;
                }
            }
        }

        if (valid)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}