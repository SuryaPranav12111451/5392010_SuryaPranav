#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), cmp);

    int min_unfairness = arr[k-1] - arr[0];
    for (int i = 1; i <= n - k; i++) {
        int unfairness = arr[i + k - 1] - arr[i];
        if (unfairness < min_unfairness) {
            min_unfairness = unfairness;
        }
    }

    printf("%d\n", min_unfairness);
    return 0;
}