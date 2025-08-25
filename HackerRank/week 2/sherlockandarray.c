#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100005

int arr[MAX_N];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        long long total = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            total += arr[i];
        }

        long long left = 0;
        int found = 0;
        for(int i = 0; i < n; i++) {
            if(left == total - left - arr[i]) {
                found = 1;
                break;
            }
            left += arr[i];
        }
        if(found)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}