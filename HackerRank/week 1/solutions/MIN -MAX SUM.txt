MIN-MAX SUM

#include <stdio.h>
int main() {
    long numbers[5], total = 0;
    long smallest, largest;
    for (int i = 0; i < 5; i++) {
        scanf("%ld", &numbers[i]);
        total += numbers[i];
    }
    smallest = largest = numbers[0];
    for (int i = 1; i < 5; i++) {
        if (numbers[i] < smallest)
            smallest = numbers[i];
        if (numbers[i] > largest)
            largest = numbers[i];
    }
    long min_total = total - largest;
    long max_total = total - smallest;
    printf("%ld %ld\n", min_total, max_total);
    return 0;
}

.....................................................................................
