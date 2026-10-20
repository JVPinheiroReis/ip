#include <stdio.h>

typedef struct {
    float c;
    int e;
} PolTerm;

int main(void) {
    int n;

    scanf("%d%*c", &n);

    int i, j, k, l;
    for (i = 0; i < n; i++) {
        char op;
        int n1;
        int n2;
        PolTerm p1[51] = {0};
        PolTerm p2[51] = {0};

        scanf("%c%*c", &op);

        scanf("%d%*c", &n1);
        for (j = 0; j < n1; j++) {
            scanf("%f %d%*c", &p1[j].c, &p1[j].e);
        }
        p1[n1].e = -1;

        scanf("%d%*c", &n2);
        for (j = 0; j < n2; j++) {
            scanf("%f %d%*c", &p2[j].c, &p2[j].e);
        }
        p2[n2].e = -1;

        PolTerm p3[100] = {0};

        j = 0;
        k = 0;
        l = 0;
        while (j < n1 || k < n2) {
            if (p1[j].e > p2[k].e) {
                p3[l].c += p1[j].c;
                p3[l].e = p1[j].e;
                j++;
            }
            else if (p1[j].e == p2[k].e) {
                p3[l].c += op == '+' ? p1[j].c + p2[k].c : p1[j].c - p2[k].c;
                p3[l].e = p1[j].e;
                j++;
                k++;
            }
            else {
                p3[l].c += op == '+' ? p2[k].c : -p2[k].c;
                p3[l].e = p2[k].e;
                k++;
            }
            l++;
        }

        int n3 = l;

        for (j = 0; j < n3; j++) {
            if (p3[j].c > 0) {
                printf("+%.2f", p3[j].c);
            }
            else if (p3[j].c < 0) {
                printf("%.2f", p3[j].c);
            }

            if (p3[j].c != 0 && p3[j].e != 0) {
                printf("X^%d", p3[j].e);
            }
        }
        printf("\n");
    }

    return 0;
}