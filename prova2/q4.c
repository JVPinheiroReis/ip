#include <stdio.h>
#define N 1025

int get_string_len(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
    }

    return i;
}

void rotacionar(char *texto, int k) {
    char tmp[N];

    int s_size = get_string_len(texto);

    int i, j;
    for (i = 0; texto[i] != '\0'; i++) {
        tmp[i] = texto[i];
    }
    tmp[i] = '\0';

    i = k % s_size;
    j = 0;
    while (j <= s_size - 1) {
        if (i > s_size - 1) {
            i -= s_size;
        }

        texto[i] = tmp[j];

        i++;
        j++;
    }
}

int main(void) {
    char s[N] = "\0";
    int k;

    scanf("%1024[^\n]%*c", s);
    scanf("%d", &k);

    rotacionar(s, k);

    printf("%s\n", s);

    return 0;
}