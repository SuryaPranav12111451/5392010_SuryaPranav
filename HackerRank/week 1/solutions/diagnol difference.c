#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n];
    
    for (int i = 0; i < n * n; i++) {
        scanf("%d", *((arr) + i / n) + i % n);
    }

    int primary_sum = 0, secondary_sum = 0;

   
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        primary_sum += arr[i][i];
        secondary_sum += arr[i][j];
    }

    printf("%d\n", abs(primary_sum - secondary_sum));
    return 0;
}
