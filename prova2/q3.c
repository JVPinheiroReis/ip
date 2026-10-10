#include <stdio.h>

char alterna_letra(char c) {
    return 0;
}

void processar(char *str, int *maiusculas, int *digitos, int *espacos) {
    *maiusculas = 0;
    *digitos = 0;
    *espacos = 0;

    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
            *maiusculas += 1;
        }

        if ('0' <= str[i] && str[i] <= '9') {
            str[i] = '#';
            *digitos += 1;
        }
    }

    i = 0;
    j = 0;
    while (str[j] != '\0') {
        while (str[j] == ' ') {
            *espacos += 1;
            j++;
        }

        str[i] = str[j];

        i++;
        j++;
    }
    str[i] = '\0';
}

int main(void) {
    char s[1024 + 1] = "\0";

    scanf("%1024[^\n]", s);

    int maiusculas, digitos, espacos;

    processar(s, &maiusculas, &digitos, &espacos);

    printf("%s\n", s);
    printf("%d %d %d\n", maiusculas, digitos, espacos);

    return 0;
}