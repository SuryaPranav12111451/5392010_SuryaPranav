#include <stdio.h>

int birthday(int s[], int n, int d, int m) {
    int count = 0;

    // Calculate the sum of the first window
    int windowSum = 0;
    for (int i = 0; i < m && i < n; i++) {
        windowSum += s[i];
    }
    if (windowSum == d) count++;

    for (int i = m; i < n; i++) {
        windowSum += s[i] - s[i - m];
        if (windowSum == d) count++;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    int s[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    int d, m;
    scanf("%d %d", &d, &m);

    int result = birthday(s, n, d, m);
    printf("%d\n", result);

    return 0;
}