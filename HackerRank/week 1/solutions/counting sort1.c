#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, num;

    scanf("%d", &n);

    
    int *arr = (int *)malloc(n * sizeof(int));
    int *freq = (int *)calloc(100, sizeof(int));
    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;
    }

    for (i = 0; i < 100; i++) {
        printf("%d ", freq[i]);
    }

  
    free(arr);
    free(freq);

    return 0;
}
