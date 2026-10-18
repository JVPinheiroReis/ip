#include <stdio.h>

typedef struct {
    float coef;
    int exp;
} Termo;

typedef struct {
    Termo termos[100];
    int qtd;
} Polinomio;

void LePolinomio(Polinomio *p) {
    int i;
    scanf("%d", &(p->qtd));
    for (i = 0; i < p->qtd; i++) {
        scanf("%f %d", &(p->termos[i].coef), &(p->termos[i].exp));
    }
}

Polinomio SomaPolinomios(Polinomio p1, Polinomio p2) {
    Polinomio res;
    int i = 0, j = 0, k = 0;

    while (i < p1.qtd && j < p2.qtd) {
        if (p1.termos[i].exp > p2.termos[j].exp) {
            res.termos[k++] = p1.termos[i++];
        }
        else if (p1.termos[i].exp < p2.termos[j].exp) {
            res.termos[k++] = p2.termos[j++];
        }
        else {
            float soma = p1.termos[i].coef + p2.termos[j].coef;
            float abs_soma = (soma < 0) ? -soma : soma;

            if (abs_soma > 1e-5) {
                res.termos[k].coef = soma;
                res.termos[k].exp = p1.termos[i].exp;
                k++;
            }
            i++;
            j++;
        }
    }

    while (i < p1.qtd)
        res.termos[k++] = p1.termos[i++];
    while (j < p2.qtd)
        res.termos[k++] = p2.termos[j++];

    res.qtd = k;
    return res;
}

Polinomio SubtraiPolinomios(Polinomio p1, Polinomio p2) {
    Polinomio res;
    int i = 0, j = 0, k = 0;

    while (i < p1.qtd && j < p2.qtd) {
        if (p1.termos[i].exp > p2.termos[j].exp) {
            res.termos[k++] = p1.termos[i++];
        }
        else if (p1.termos[i].exp < p2.termos[j].exp) {
            res.termos[k].coef = -p2.termos[j].coef;
            res.termos[k].exp = p2.termos[j].exp;
            k++;
            j++;
        }
        else {
            float dif = p1.termos[i].coef - p2.termos[j].coef;
            float abs_dif = (dif < 0) ? -dif : dif;

            if (abs_dif > 1e-5) {
                res.termos[k].coef = dif;
                res.termos[k].exp = p1.termos[i].exp;
                k++;
            }
            i++;
            j++;
        }
    }

    while (i < p1.qtd)
        res.termos[k++] = p1.termos[i++];

    while (j < p2.qtd) {
        res.termos[k].coef = -p2.termos[j].coef;
        res.termos[k].exp = p2.termos[j].exp;
        k++;
        j++;
    }

    res.qtd = k;
    return res;
}

void ImprimePolinomio(Polinomio p) {
    int i;

    if (p.qtd == 0) {
        printf("0.00\n");
        return;
    }

    for (i = 0; i < p.qtd; i++) {
        float c = p.termos[i].coef;
        int e = p.termos[i].exp;

        if (i == 0) {
            printf(c < 0 ? "-" : "+");
        }
        else {
            printf(c < 0 ? "-" : "+");
        }
        if (c < 0) c = -c;

        if (e > 0) printf("%.2fX^%d", c, e);
        else printf("%.2f", c);
    }
    printf("\n");
}

int main(void) {
    int casos, c;
    char op[5];

    if (scanf("%d", &casos) != 1) return 0;

    for (c = 0; c < casos; c++) {
        Polinomio p1, p2, res;

        scanf("%4s", op);
        LePolinomio(&p1);
        LePolinomio(&p2);

        if (op[0] == '+') res = SomaPolinomios(p1, p2);
        else res = SubtraiPolinomios(p1, p2);

        ImprimePolinomio(res);
    }

    return 0;
}