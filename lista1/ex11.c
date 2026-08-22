#include <stdio.h>

int main(void) {
    int cp = 0, sp = 0, ci = 0, si = 0;
    int input;

    for (;;) {
        scanf("%d", &input);

        if (input == 0) {
            double mp = cp > 0 ? (double)sp / cp : (double)0;
            double mi = ci > 0 ? (double)si / ci : (double)0;

            printf("MEDIA PAR: %.6f\n", mp);
            printf("MEDIA IMPAR: %.6f\n", mi);
            return 0;
        }

        if (input % 2 == 0) {
            cp++;
            sp += input;
        }
        else {
            ci++;
            si += input;
        }
    }

    return 0;
}
