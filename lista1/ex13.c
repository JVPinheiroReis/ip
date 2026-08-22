#include <stdio.h>

int main(void) {
    double x1, x2, x3, tmp;

    scanf("%lf %lf %lf", &x1, &x2, &x3);

    if (x1 > x2) {
        tmp = x2;
        x2 = x1;
        x1 = tmp;
    }

    if (x2 > x3) {
        tmp = x3;
        x3 = x2;
        x2 = tmp;
    }

    if (x1 > x2) {
        tmp = x2;
        x2 = x1;
        x1 = tmp;
    }

    printf("%.2lf, %.2lf, %.2lf\n", x1, x2, x3);

    return 0;
}
