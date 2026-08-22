#include <math.h>
#include <stdio.h>

int main(void) {
    double x1, y1, x2, y2;

    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("A DISTANCIA ENTRE A e B = %.2lf\n", d);

    return 0;
}
