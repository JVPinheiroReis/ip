#include <stdio.h>

int reverse_n5(int n) {
    int r = 0;

    int i;
    int j;
    for (i = 10000; i >= 1; i /= 10) {
        if (n >= i) {
            for (j = 1; j <= i; j *= 10) {
                r += ((n / (i / j)) % 10) * j;
            }
            return r;
        }
    }

    return -1;
}

int main(void) {
    int n;

    scanf("%d", &n);

    if (n >= 100000) {
        printf("NUMERO INVALIDO\n");
        return 0;
    }

    if (n == reverse_n5(n)) {
        printf("PALINDROMO\n");
    }
    else {
        printf("NAO PALINDROMO\n");
    }

    return 0;
}
