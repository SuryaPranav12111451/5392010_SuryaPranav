#include <stdio.h>
#include <string.h>

int main() {
    char n_str[100001];
    long long k;

    scanf("%s %lld", n_str, &k);

    long long digit_sum = 0;
    for (int i = 0; n_str[i] != '\0'; i++) {
        digit_sum += (n_str[i] - '0');
    }

    // Multiply sum by k
    long long total = digit_sum * k;

    // Super digit can be reduced using modulo 9 (digital root)
    long long super_digit;
    if (total == 0)
        super_digit = 0;
    else
        super_digit = (total % 9 == 0) ? 9 : total % 9;

    printf("%lld\n", super_digit);
    return 0;
}
