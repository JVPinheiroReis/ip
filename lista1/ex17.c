#include <stdio.h>

int main(void) {
    int l, c, d;

    scanf("%d %d %d", &l, &c, &d);

    int i;
    int j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            if (i == j || (i - d <= j && j <= i + d)) {
                printf("(%2d,%2d)", i + 1, j + 1);
            }
            else {
                printf(".......");
            }
        }
        printf("\n");
    }

    return 0;
}
