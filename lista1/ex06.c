#include <stdio.h>

int main(void) {
    unsigned int mat;
    double p1, p2, p3, p4, p5, p6, p7, p8;
    double l1, l2, l3, l4, l5;
    double tf;
    unsigned int freq;

    for (;;) {
        int lidos = scanf(
            "%u %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %u",
            &mat, &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &l1, &l2, &l3, &l4,
            &l5, &tf, &freq);

        if (lidos != 16 || tf == -1) {
            return 0;
        }

        double mp = (p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8) / 8.0;
        double ml = (l1 + l2 + l3 + l4 + l5) / 5.0;
        double nf = (0.7 * mp) + (0.15 * ml) + (0.15 * tf);
        double pfreq = (double)freq / 128;

        int aprovado_nota = nf >= 6;
        int aprovado_freq = pfreq >= 0.75;

        const char *sf;
        if (aprovado_nota && aprovado_freq) {
            sf = "APROVADO";
        }
        else if (aprovado_nota) {
            sf = "REPROVADO POR FREQUENCIA";
        }
        else if (aprovado_freq) {
            sf = "REPROVADO POR NOTA";
        }
        else {
            sf = "REPROVADO POR NOTA E POR FREQUENCIA";
        }

        printf("Matricula: %u, Nota Final: %.2lf, Situacao Final: %s\n", mat,
               nf, sf);
    }
}
