lonely integer


#include <stdio.h>

int main() {
    int n, num;
    scanf("%d", &n);
    
    int max = 100000; 
    int freq[max];
    
    for (int i = 0; i < max; i++) {
        freq[i] = 0;
    }


    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        freq[num]++;
    }

    for (int i = 0; i < max; i++) {
        if (freq[i] == 1) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
