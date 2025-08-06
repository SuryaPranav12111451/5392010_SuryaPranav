#include <stdio.h>
#include <ctype.h>

int main() {
    char s[1001];
    fgets(s, sizeof(s), stdin);

    unsigned int mask = 0; 

    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            char ch = tolower(s[i]);
            mask |= (1 << (ch - 'a')); 
        }
    }

    if (mask == (1 << 26) - 1)
        printf("pangram\n");
    else
        printf("not pangram\n");

    return 0;
}

