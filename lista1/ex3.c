#include <stdio.h>

int main(void) {
    double a, b, c;

    scanf("%lf %lf %lf", &a, &b, &c);

    double delta = b * b - 4 * a * c;

    printf("O VALOR DE DELTA E = %.2lf\n", delta);

    return 0;
}
