#include <stdio.h>

int trocar_vizinhos(int *vetor, int n) {
    if (n % 2 != 0) n--;

    int tmp;
    int c = 0;

    int i;
    for (i = 0; i < n; i += 2) {
        c++;

        tmp = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = tmp;
    }

    return c;
}

int main(void) {
    int N;

    scanf("%d", &N);

    int n[N];

    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }

    int c = trocar_vizinhos(n, N);

    for (i = 0; i < N; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");

    printf("%d\n", c);

    return 0;
}