#include <stdio.h>

int main(void) {
    int N;

    scanf("%d", &N);
    getchar();

    int i;
    int j;
    for (i = 0; i < N; i++) {
        char s[10000] = "";

        fgets(s, sizeof(s), stdin);

        int cl = 0;
        int cv = 0;
        int cc = 0;
        for (j = 0; s[j] != '\n'; j++) {
            char c = s[j];
            if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
                cl++;
                if ((c == 'A' || c == 'a') || (c == 'E' || c == 'e') ||
                    (c == 'I' || c == 'i') || (c == 'O' || c == 'o') ||
                    (c == 'U' || c == 'u')) {
                    cv++;
                }
                else {
                    cc++;
                }
            }
        }

        printf("Letras = %d\n", cl);
        printf("Vogais = %d\n", cv);
        printf("Consoantes = %d\n", cc);
    }

    return 0;
}