#include <stdio.h>

/* Retorna e tal que b^e == a (e >= 1), ou 0 se a nao for potencia de b. */
int calcula_log(int a, int b) {
    long long pot = b;
    int e = 1;

    while (pot < a) {
        pot *= b;
        e++;
    }

    return pot == a ? e : 0;
}

/* Se n for potencia de um primo k, guarda k e o expoente p e retorna 1. */
int potencia_prima(int n, int *k, int *p) {
    int i;
    for (i = 2; i <= n; i++) {
        if (n % i == 0) {
            break;
        }
    }

    /* o menor divisor >= 2 de n e sempre primo */
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
