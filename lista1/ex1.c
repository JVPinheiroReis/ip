#include <stdio.h>

const int VALOR_POP = 1;
const int VALOR_GER = 5;
const int VALOR_ARQ = 10;
const int VALOR_CAD = 20;

int main(void) {
    int n, pub_total;
    double por_pop, por_ger, por_arq, por_cad, renda;

    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        scanf("%d %lf %lf %lf %lf", &pub_total, &por_pop, &por_ger, &por_arq,
              &por_cad);

        renda = pub_total *
                ((por_pop / 100 * VALOR_POP) + (por_ger / 100 * VALOR_GER) +
                 (por_arq / 100 * VALOR_ARQ) + (por_cad / 100 * VALOR_CAD));

        printf("A RENDA DO JOGO N. %d E = %.2lf\n", i + 1, renda);
    }

    return 0;
}
