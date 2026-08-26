#include <stdio.h>

int main(void) {
    float a, b, c, d, e, f;

    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    scanf("%f", &d);
    scanf("%f", &e);
    scanf("%f", &f);

    float det = a * e - b * d;

    float x = (c * e - b * f) / det;
    float y = (a * f - c * d) / det;

    printf("O VALOR DE X E = %.2f\n", x);
    printf("O VALOR DE Y E = %.2f\n", y);

    return 0;
}
