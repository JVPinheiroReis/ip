#include <stdio.h>

int days_until_month(int m) {
    int r = 0;
    m -= 1;

    switch (m) {
    case 12:
        r += 31;

    case 11:
        r += 30;

    case 10:
        r += 31;

    case 9:
        r += 30;

    case 8:
        r += 31;

    case 7:
        r += 31;

    case 6:
        r += 30;

    case 5:
        r += 31;

    case 4:
        r += 30;

    case 3:
        r += 31;

    case 2:
        r += 28;

    case 1:
        r += 31;
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
