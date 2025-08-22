#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_Q 100000

typedef struct {
    int *data;
    int size;
    int capacity;
} Sequence;

void append(Sequence *seq, int val) {
    if (seq->size == seq->capacity) {
        seq->capacity = seq->capacity * 2 + 1;
        seq->data = realloc(seq->data, seq->capacity * sizeof(int));
    }
    seq->data[seq->size++] = val;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    Sequence *seqArr = malloc(n * sizeof(Sequence));
    for (int i = 0; i < n; i++) {
        seqArr[i].data = malloc(sizeof(int) * 1);
        seqArr[i].size = 0;
        seqArr[i].capacity = 1;
    }

    int lastAnswer = 0;
    for (int qi = 0; qi < q; qi++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        int idx = (x ^ lastAnswer) % n;
        if (type == 1) {
            append(&seqArr[idx], y);
        } else if (type == 2) {
            int valueIdx = y % seqArr[idx].size;
            lastAnswer = seqArr[idx].data[valueIdx];
            printf("%d\n", lastAnswer);
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(seqArr[i].data);
    }
    free(seqArr);

    return 0;
}