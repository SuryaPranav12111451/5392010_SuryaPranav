flipping bits

#include <stdio.h>

int main() {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        unsigned int n;
        scanf("%u", &n);

        unsigned int result = 0;
        for (int bit = 0; bit < 32; bit++) {
            // Check if the bit is 0 or 1
            unsigned int bit_val = (n >> bit) & 1;
          
            if (bit_val == 0) {
                result |= (1U << bit);
            }
        }
        printf("%u\n", result);
    }
    return 0;
}
