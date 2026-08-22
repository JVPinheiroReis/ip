#include <stdio.h>

int main(void) {
    int n1, n2, n3, r;

    scanf("%d %d %d", &n1, &n2, &n3);

    if (n1 >= 10 || n2 >= 10 || n3 >= 10) {
        printf("DIGITO INVALIDO\n");
        return 0;
    }

    r = (n1 * 100) + (n2 * 10) + (n3 * 1);

    printf("%d, %d\n", r, r * r);

    return 0;
}
