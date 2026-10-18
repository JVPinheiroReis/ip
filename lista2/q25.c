#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int den;
} Fraction;

int equivalent_fractions(Fraction f1, Fraction f2) {
    return (long long)f1.num * f2.den == (long long)f2.num * f1.den;
}

int main(void) {
    int n;

    scanf("%d%*c", &n);

    Fraction f;
    Fraction *fs = NULL;
    Fraction *tmp = NULL;

    char s[1000 + 1] = "\0";

    int i, j, k, l;
    for (i = 0; i < n; i++) {
        if (fgets(s, sizeof(s), stdin) == NULL) break;

        j = 0;
        char *p = s;

        while (sscanf(p, "%d/%d", &f.num, &f.den) == 2) {
            int consumed = 0;
            sscanf(p, "%d/%d%n", &f.num, &f.den, &consumed);

            tmp = realloc(fs, (j + 1) * sizeof(Fraction));

            if (tmp == NULL) {
                free(fs);
                return 1;
            }

            fs = tmp;
            fs[j] = f;

            j++;
            p += consumed;

            while (*p == ' ')
                p++;

            if (*p == '\n' || *p == '\0') break;
        }

        printf("Caso de teste %d\n", i + 1);

        int c = 0;

        for (k = 0; k < j; k++) {
            for (l = k + 1; l < j; l++) {
                if (equivalent_fractions(fs[k], fs[l])) {
                    printf("%d/%d equivalente a %d/%d\n",
                           fs[k].num,
                           fs[k].den,
                           fs[l].num,
                           fs[l].den);
                    c = 1;
                }
            }
        }

        if (c == 0) {
            printf("Nao ha fracoes equivalentes na sequencia\n");
        }

        free(fs);
        fs = NULL;
    }

    return 0;
}
