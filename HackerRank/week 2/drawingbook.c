
#include <stdio.h>

int pageCount(int n, int p) {
    // from the front
    int front = p / 2;
    // from the back
    int back = (n / 2) - (p / 2);
    // return the minimum of the two
    return (front < back) ? front : back;
}

// Example usage
int main() {
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);
    printf("%d\n", pageCount(n, p));
    return 0;
}