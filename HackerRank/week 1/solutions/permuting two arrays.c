#include <stdio.h>
#include <stdlib.h>
int compareAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compareDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int a[n], b[n];

    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);

    qsort(a, n, sizeof(int), compareAsc);
    qsort(b, n, sizeof(int), compareDesc);

    int ok = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] + b[i] < k) {
            ok = 0;
            break;
        }
    }

    if (ok)
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
