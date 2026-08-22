#include <stdio.h>

int main(void) {
    double s;
    int np;
    char p;
    double m;

    scanf("%lf %d %c %lf", &s, &np, &p, &m);

    char *tp;
    if (p == 'E') {
        tp = "ENFERMARIA";
    }
    else if (p == 'A') {
        tp = "APARTAMENTO";
    }
    else {
        printf("TIPO DE PLANO INVALIDO\n");
        return 0;
    }

    double sl;
    double tpp;
    if (s <= 1800 && p == 'E') {
        tpp = ((double)25 / 100) * np * m;
    }
    else if (s <= 1800 && p == 'A') {
        tpp = ((double)30 / 100) * np * m;
    }
    else if (s <= 5000 && p == 'E') {
        tpp = ((double)28 / 100) * np * m;
    }
    else if (s <= 5000 && p == 'A') {
        tpp = ((double)35 / 100) * np * m;
    }
    else if (p == 'E') {
        tpp = ((double)31 / 100) * np * m;
    }
    else if (p == 'A') {
        tpp = ((double)40 / 100) * np * m;
    }

    sl = s - tpp;

    if (sl < ((double)30 / 100) * s) {
        printf("DESCONTO NAO AUTORIZADO\n");
        return 0;
    }

    printf("%s %.2lf\n", tp, tpp);

    return 0;
}
