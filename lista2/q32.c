#include <stdio.h>
#include <stdlib.h>

int in(int e, int v[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        if (e == v[i]) {
            return 1;
        }
    }

    return 0;
}

int acertos(int ap[], int st[]) {
    int r = 0;

    int i;
    for (i = 0; i < 6; i++) {
        if (in(ap[i], st, 6)) {
            r++;
        }
    }

    return r;
}

int main() {
    int N;
    int i, j;
    int c = 0;

    int **m = NULL;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        m = (int **)realloc(m, (i + 1) * sizeof(int *));
        m[i] = (int *)calloc(6, sizeof(int));

        for (j = 0; j < 6; j++) {
            scanf("%d", &m[i][j]);
        }

        c++;
    }

    int st[6];
    for (i = 0; i < 6; i++) {
        scanf("%d", &st[i]);
    }

    int sen = 0;
    int qui = 0;
    int qua = 0;
    for (i = 0; i < c; i++) {
        switch (acertos(m[i], st)) {
            case 6: sen++; break;
            case 5: qui++; break;
            case 4: qua++; break;
        }
    }

    if (sen) printf("Houve %d acertador(es) da sena\n", sen);
    else printf("Nao houve acertador para sena\n");

    if (qui) printf("Houve %d acertador(es) da quina\n", qui);
    else printf("Nao houve acertador para sena\n");

    if (qua) printf("Houve %d acertador(es) da quadra\n", qua);
    else printf("Nao houve acertador para sena\n");

    return 0;
}