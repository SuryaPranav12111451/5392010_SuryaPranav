#include <stdio.h>


int popcount(unsigned long long int n) {
    int count = 0;
    while (n) {
        n &= (n - 1); 
        count++;
    }
    return count;
}

int main() {
    int t;
    scanf("%d", &t); 

    while (t--) {
        unsigned long long int n;
        scanf("%llu", &n); // Read the initial value of N

       
        if (n == 1) {
            printf("Richard\n");
            continue;
        }

        
        if (popcount(n - 1) & 1) {
            printf("Louise\n");
        } else {
            printf("Richard\n");
        }
    }
    return 0;
}