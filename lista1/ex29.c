#include <stdio.h>

double fact(int n) {
    double r = 1;
    int i;
    for (i = n; i >= 1; i--) {
        r *= i;
    }
    return r;
}

double power(double n, int e) {
    double r = 1;
    int i;
    for (i = 0; i < e; i++) {
        r *= n;
    }
    return r;
}

int main(void) {
    double x;
    int N;

    scanf("%lf %d", &x, &N);

    int n;
    double t = 0;
    for (n = 0; n <= N; n++) {
        t += power(x, n) / fact(n);
    }

    printf("e^%.2lf = %.6lf\n", x, t);

    return 0;
}
