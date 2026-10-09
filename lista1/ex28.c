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
    long long inteira = 0, decimal = 0;
    long long den = 1;
    int sinal = 1;

    int c = getchar();
    while (c == ' ' || c == '\n') {
        c = getchar();
    }

    if (c == '-') {
        sinal = -1;
        c = getchar();
    }

    while (c >= '0' && c <= '9') {
        inteira = inteira * 10 + (c - '0');
        c = getchar();
    }

    if (c == '.') {
        while ((c = getchar()) >= '0' && c <= '9') {
            decimal = decimal * 10 + (c - '0');
            den *= 10;
        }
    }

    long long num = sinal * (inteira * den + decimal);
    long long d = mdc(num < 0 ? -num : num, den);

    num /= d;
    den /= d;

    printf("%lld/%lld\n", num, den);

    return 0;
}
