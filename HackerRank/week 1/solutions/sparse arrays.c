sparse arrays

#include <stdio.h>
#include <string.h>

#define MAX 1000

struct Entry {
    char str[21];
    int count;
};

int main() {
    int n, q;
    scanf("%d", &n);
    
    struct Entry entries[MAX];
    int entryCount = 0;

    for (int i = 0; i < n; i++) {
        char temp[21];
        scanf("%s", temp);

        int found = 0;
        for (int j = 0; j < entryCount; j++) {
            if (strcmp(entries[j].str, temp) == 0) {
                entries[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(entries[entryCount].str, temp);
            entries[entryCount].count = 1;
            entryCount++;
        }
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        char query[21];
        scanf("%s", query);
        int found = 0;
        for (int j = 0; j < entryCount; j++) {
            if (strcmp(entries[j].str, query) == 0) {
                printf("%d\n", entries[j].count);
                found = 1;
                break;
            }
        }
        if (!found)
            printf("0\n");
    }

    return 0;
}
