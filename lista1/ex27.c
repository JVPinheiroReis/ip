#include <stdio.h>

double min(double n1, double n2, double n3) {
    if (n1 <= n2 && n1 <= n3)
        return n1;
    else if (n2 <= n1 && n2 <= n3)
        return n2;
    else
        return n3;
}

double max(double n1, double n2, double n3) {
    if (n1 >= n2 && n1 >= n3)
        return n1;
    else if (n2 >= n1 && n2 >= n3)
        return n2;
    else
        return n3;
}

double med(double n1, double n2, double n3) {
    if ((n1 <= n2 && n2 <= n3) || (n3 <= n2 && n2 <= n1)) {
        return n2;
    }
    else if ((n2 <= n1 && n1 <= n3) || (n3 <= n1 && n1 <= n2)) {
        return n1;
    }
    else {
        return n3;
    }
}

int main(void) {
    int opt;
    double n1, n2, n3;

    scanf("%d", &opt);
    scanf("%lf %lf %lf", &n1, &n2, &n3);

    double min_n = min(n1, n2, n3);
    double max_n = max(n1, n2, n3);
    double med_n = med(n1, n2, n3);

    if (opt == 1) {
        printf("%.2lf %.2lf %.2lf\n", min_n, med_n, max_n);
    }
    if (opt == 2) {
        printf("%.2lf %.2lf %.2lf\n", max_n, med_n, min_n);
    }
    if (opt == 3) {
        printf("%.2lf %.2lf %.2lf\n", med_n, max_n, min_n);
    }

    return 0;
}
