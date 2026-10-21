#include <stdio.h>

int main(void) {
    typedef struct {
        int M;
        int CT;
    } I;

    int N;

    int i;
    int c = 1;
    while (1) {
        scanf("%d", &N);

        I is[N];

        if (N == 0) return 0;

        for (i = 0; i < N; i++) {
            scanf("%d %d", &is[i].M, &is[i].CT);
        }

        printf("Cidade # %d\n", c);
        printf("");
        printf("Consumo medio: %.2f m3.");

        c++;
    }

    return 0;
}