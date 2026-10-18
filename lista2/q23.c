#include <stdio.h>

void draw_filled_square(int m[][200], int x, int y, int r, int c) {
    int i, j;
    for (i = -1 * r; i <= r; i++) {
        for (j = -1 * r; j <= r; j++) {
            m[y + i][x + j] = c;
        }
    }
}

void draw_empty_square(int m[][200], int x, int y, int r, int c) {
    int i, j;
    for (i = -1 * r; i <= r; i++) {
        for (j = -1 * r; j <= r; j++) {
            if (i == -1 * r || i == r || j == -1 * r || j == r) {
                m[y + i][x + j] = c;
            }
        }
    }
}

int main(void) {
    int N, b;

    scanf("%d %d", &N, &b);

    int m[200][200];

    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = b;
        }
    }

    int x, y, c;
    int r, s;

    scanf("%d %d", &x, &y);

    while (x != -1 && y != -1) {
        scanf("%d %d %d", &c, &r, &s);

        if ((0 <= x - r && x + r <= N - 1) && (0 <= y - r && y + r <= N - 1)) {
            if (s == 1) {
                draw_empty_square(m, x, y, r, c);
            }
            if (s == 2) {
                draw_filled_square(m, x, y, r, c);
            }
        }

        scanf("%d %d", &x, &y);
    }

    printf("P2\n");
    printf("%d %d\n", N, N);
    printf("255\n");

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}