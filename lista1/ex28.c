#include <stdio.h>

long long mdc(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(void) {
    long long input = 0, decimal = 0;
    long long den = 1;

    scanf("%lld", &input);

    char c = getchar();
    if (c == '.') {
        while ((c = getchar()) >= '0' && c <= '9') {
            decimal = decimal * 10 + (c - '0');
            den *= 10;
        }
    }

    long long num = input * den + decimal;
    long long d = mdc(num, den);

    num /= d;
    den /= d;

    printf("%lld/%lld\n", num, den);

    return 0;
}
