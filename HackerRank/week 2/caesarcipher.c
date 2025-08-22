#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n, k;
    char s[101];
    
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%d", &k);

    for(int i = 0; i < n; i++) {
        char c = s[i];
        if(isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            printf("%c", (c - base + k) % 26 + base);
        } else {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}