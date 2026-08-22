#include <stdio.h>

int main(void) {
    double med, max = 0, min, tmp;

    scanf("%lf", &min);

    int i;
    for (i = 0; i < 2; i++) {
        scanf("%lf", &med);

        if (med > max) {
            tmp = max;
            max = med;
            med = tmp;
        }
        else if (med < min) {
            tmp = min;
            min = med;
            med = tmp;
        }
    }

    printf("%.2lf, %.2lf, %.2lf\n", min, med, max);

    return 0;
}
