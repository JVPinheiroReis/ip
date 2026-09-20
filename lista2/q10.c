#include <math.h>
#include <stdio.h>

int main(void) {
    int n;

    typedef struct {
        double u;
        double x;
        double y;
        double z;
    } Dot;

    Dot p1, p2;

    scanf("%d", &n);

    scanf("%lf %lf %lf %lf", &p1.u, &p1.x, &p1.y, &p1.z);

    int i;
    for (i = 0; i < n - 1; i++) {
        scanf("%lf %lf %lf %lf", &p2.u, &p2.x, &p2.y, &p2.z);

        printf("%.2lf\n", sqrt(pow(p2.u - p1.u, 2) + pow(p2.x - p1.x, 2) +
                               pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2)));

        p1 = p2;
    }

    return 0;
}