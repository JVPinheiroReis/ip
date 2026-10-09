#include <stdio.h>

int calcula_log(int a, int b) {
    int e = 1;
    int hold_b = b;

    while (b <= a) {
        if (b == a) {
            return e;
        }

        e++;
        b *= hold_b;
    }

    return 0;
}

int eh_potencia(int a, int b) {
    int hold_b = b;

    while (b <= a) {
        if (b == a) {
            return 1;
        }

        b *= hold_b;
    }

    return 0;
}

int potencia_prima(int n, int *k, int *p) {
    int c = 0;

    int i;
    for (i = 2; i <= n; i++) {
        if (n % i == 0) {
            break;
        }
    }

    if (eh_potencia(n, i)) {
        *k = i;
        *p = calcula_log(n, i);
        return 1;
    }

    return 0;
}

int main(void) {
    int N;

    scanf("%d", &N);

    int k, p;

    int i, c = 0;
    for (i = 2; c < N; i++) {
        if (potencia_prima(i, &k, &p)) {
            printf("%d : %d^%d\n", i, k, p);

            c++;
        }
    }

    return 0;
}