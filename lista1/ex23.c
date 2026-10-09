#include <stdio.h>

int inverte(int n) {
    int r = 0;

    while (n > 0) {
        r = r * 10 + n % 10;
        n /= 10;
    }

    return r;
}

int main(void) {
    int n;

    scanf("%d", &n);

    if (n < 0 || n >= 100000) {
        printf("NUMERO INVALIDO\n");
        return 0;
    }

    if (n == inverte(n)) {
        printf("PALINDROMO\n");
    }
    else {
        printf("NAO PALINDROMO\n");
    }

    return 0;
}
