#include <stdio.h>
#include <string.h>
#define MAX 26


void findMinMax(int arr[], int n, int *min, int *max, int *minCount, int *maxCount) {
    *min = 0x7fffffff;
    *max = 0;
    *minCount = 0;
    *maxCount = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            if (arr[i] < *min) *min = arr[i];
            if (arr[i] > *max) *max = arr[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] == *min) (*minCount)++;
        if (arr[i] == *max) (*maxCount)++;
    }
}

const char* isValid(char *s) {
    int freq[MAX] = {0};
    int len = strlen(s);

    
    for (int i = 0; i < len; ++i) freq[s[i] - 'a']++;

    int min, max, minCount, maxCount;
    findMinMax(freq, MAX, &min, &max, &minCount, &maxCount);

    if (min == max) return "YES";
   
    if ((max - min == 1) && (maxCount == 1)) return "YES";
   
    if ((min == 1) && (minCount == 1) && (max == min + 1 || max == min)) return "YES";
    return "NO";
}

int main() {
    char s[100005];
    scanf("%s", s);
    printf("%s\n", isValid(s));
    return 0;
}