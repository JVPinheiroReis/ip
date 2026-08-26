#include <stdio.h>

int main(void) {
    int v, n100 = 0, n50 = 0, n10 = 0, m1 = 0;

    scanf("%d", &v);

    while (v >= 100) {
        n100++;
        v -= 100;
    }
    while (v >= 50) {
        n50++;
        v -= 50;
    }
    while (v >= 10) {
        n10++;
        v -= 10;
    }
    while (v >= 1) {
        m1++;
        v -= 1;
    }

    printf("NOTAS DE 100 = %d\n", n100);
    printf("NOTAS DE 50 = %d\n", n50);
    printf("NOTAS DE 10 = %d\n", n10);
    printf("MOEDAS DE 1 = %d\n", m1);

    return 0;
}
