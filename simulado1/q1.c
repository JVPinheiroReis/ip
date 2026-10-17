#include <stdio.h>

int calcula_log(int a, int b) {
    long long pot = b;
    int e = 1;

    while (pot < a) {
        pot *= b;
        e++;
    }

    return pot == a ? e : 0;
}

int potencia_prima(int n, int *k, int *p) {
    int i;
    for (i = 2; i <= n; i++) {
        if (n % i == 0) {
            break;
        }
    }

    int e = calcula_log(n, i);
    if (e > 0) {
        *k = i;
        *p = e;
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
