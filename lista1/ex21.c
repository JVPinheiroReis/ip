#include <stdio.h>

int days_in_month(int m) {
    switch (m) {
    case 2:
        return 28;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;

    default:
        return 31;
    }
}

int days_until_month(int m) {
    int r = 0;

    int i;
    for (i = 1; i < m; i++) {
        r += days_in_month(i);
    }

    return r;
}

int main(void) {
    int d, m, a;

    scanf("%d/%d/%d", &d, &m, &a);

    int t = days_until_month(m) + d;

    if (((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) && m >= 2) {
        t++;
    }

    printf("NUMERO DE DIAS E %d\n", t);

    return 0;
}
