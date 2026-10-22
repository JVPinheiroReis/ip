#include <stdio.h>

typedef struct {
    int MI;
    int CI;
} I;

void bubble_sort(I *Is, int n) {
    int i, c;

    I tmp;

    do {
        c = 0;
        for (i = 0; i < n - 1; i++) {
            if (Is[i].CI > Is[i + 1].CI) {
                tmp = Is[i];
                Is[i] = Is[i + 1];
                Is[i + 1] = tmp;

                c = 1;
            }
        }
    }
    while (c);
}

int main(void) {
    int N;
    int i, c = 1;

    while (1) {
        scanf("%d", &N);

        if (N == 0) return 0;

        I Is[N];
        int MT = 0;
        int CT = 0;

        for (i = 0; i < N; i++) {
            scanf("%d %d", &Is[i].MI, &Is[i].CI);

            CT += Is[i].CI;

            Is[i].CI -= Is[i].CI % Is[i].MI;
        }

        printf("Cidade # %d\n", c);
        for (i = 0; i < N; i++) {
            printf("%d-%d ", Is[i].MI, Is[i].CI / Is[i].MI);
        }
        printf("Consumo medio: %.2f m3.", (double)MT / CT);

        c++;
    }

    return 0;
}