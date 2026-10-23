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
            if ((Is[i].CI / Is[i].MI) > (Is[i + 1].CI / Is[i + 1].MI)) {
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
    int N, MT, CT;
    int i, tmp_MT, tmp_CT;

    int c = 1;
    while (1) {
        N = 0, MT = 0, CT = 0;

        if (c != 1) printf("\n");

        scanf("%d", &N);

        if (N == 0) return 0;

        I Is[N];

        for (i = 0; i < N; i++) {
            scanf("%d %d", &Is[i].MI, &Is[i].CI);

            MT += Is[i].MI;
            CT += Is[i].CI;

            Is[i].CI -= Is[i].CI % Is[i].MI;
        }

        bubble_sort(Is, N);

        printf("Cidade# %d:\n", c);

        tmp_MT = 0, tmp_CT = 0;
        for (i = 0; i < N; i++) {
            if (Is[i].CI * tmp_MT == tmp_CT * Is[i].MI) {
                tmp_MT += Is[i].MI;
                tmp_CT += Is[i].CI;
            }
            else {
                printf("%d-%d ", tmp_MT, tmp_CT / tmp_MT);

                tmp_MT = Is[i].MI;
                tmp_CT = Is[i].CI;
            }
        }
        printf("%d-%d\n", tmp_MT, tmp_CT / tmp_MT);

        printf("Consumo medio: %.2lf m3.\n", (double)CT / MT);

        c++;
    }

    return 0;
}