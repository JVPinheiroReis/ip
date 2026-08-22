#include <stdio.h>

int main(void) {
    float a, b, c, d;

    scanf("%f %f %f %f", &a, &b, &c, &d);

    float det = a * d - b * c;

    printf("O VALOR DO DETERMINANTE E = %.2f\n", det);

    return 0;
}
