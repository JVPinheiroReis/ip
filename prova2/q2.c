#include <stdio.h>

int distancia_ocorrencias(char *texto, char caractere) {
    int index1 = -1;
    int index2 = -1;

    int i;
    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == caractere) {
            index1 = i;
            break;
        }
    }
    i++;

    for (; texto[i] != '\0'; i++) {
        if (texto[i] == caractere) {
            index2 = i;
        }
    }

    if (index1 != -1 && index2 != -1) {
        return index2 - index1;
    }

    return -1;
}

int main(void) {
    char s[1024 + 1] = "\0";
    char c;

    scanf("%1024[^\n]%*c", s);
    scanf("%c", &c);

    printf("%d\n", distancia_ocorrencias(s, c));

    return 0;
}