#include <stdio.h>
#include <string.h>

char lowercase(char c) {
    if ('A' <= c && c <= 'Z') return c + 'a' - 'A';
    return c;
}

int vogal(char c) {
    c = lowercase(c);

    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': return 1;
        default: return 0;
    }
}

int digrafo_inseparavel(char c1, char c2) {
    c1 = lowercase(c1);
    c2 = lowercase(c2);

    if (c2 == 'h') {
        if (c1 == 'c') return 1;
        if (c1 == 'l') return 1;
        if (c1 == 'n') return 1;
        return 0;
    }

    if (c2 == 'l') {
        if (c1 == 'b') return 1;
        if (c1 == 'c') return 1;
        if (c1 == 'f') return 1;
        if (c1 == 'g') return 1;
        if (c1 == 'p') return 1;
        return 0;
    }

    if (c2 == 'r') {
        if (c1 == 'b') return 1;
        if (c1 == 'c') return 1;
        if (c1 == 'd') return 1;
        if (c1 == 'f') return 1;
        if (c1 == 'g') return 1;
        if (c1 == 'p') return 1;
        if (c1 == 't') return 1;
        if (c1 == 'v') return 1;
        return 0;
    }

    if (c2 == 'u') {
        if (c1 == 'g') return 1;
        if (c1 == 'q') return 1;
        return 0;
    }

    return 0;
}

int ditongo(char c1, char c2) {
    c1 = lowercase(c1);
    c2 = lowercase(c2);

    if (c1 == 'a') {
        if (c2 == 'e') return 1;
        if (c2 == 'i') return 1;
        if (c2 == 'o') return 1;
        if (c2 == 'u') return 1;
    }

    if (c1 == 'e') {
        if (c2 == 'i') return 1;
        if (c2 == 'u') return 1;
    }

    if (c1 == 'i') {
        if (c2 == 'a') return 1;
        if (c2 == 'o') return 1;
        if (c2 == 'u') return 1;
    }

    if (c1 == 'o') {
        if (c2 == 'e') return 1;
        if (c2 == 'i') return 1;
        if (c2 == 'u') return 1;
    }

    if (c1 == 'u' && c2 == 'i') return 1;

    return 0;
}

void digere_string(char src[100 + 1], char dest[][10 + 1]) {
    int i = 0;
    int j = 0;
    while (src[i] != '\0') {
        char chunk[5 + 1] = {'\0'};

        if (digrafo_inseparavel(src[i], src[i + 1]) ||
            ditongo(src[i], src[i + 1])) {
            chunk[0] = src[i];
            i++;
            chunk[1] = src[i];
        }
        else if (vogal(src[i]) && !vogal(src[i + 1]) && !vogal(src[i + 2]) &&
                 !digrafo_inseparavel(src[i + 1], src[i + 2])) {
            chunk[0] = src[i];
            i++;
            chunk[1] = src[i];
        }
        else {
            chunk[0] = src[i];
        }

        strcat(dest[j], chunk);

        i++;
        j++;
    }
}

int main(void) {
    char rw[100 + 1] = {'\0'};
    char dw[100 + 1][10 + 1] = {{'\0'}};

    scanf("%100[^\n]%*c", rw);

    digere_string(rw, dw);

    int i;
    for (i = 0; strlen(dw[i]) > 0; i++) {
        printf("%s ", dw[i]);
    }
    printf("\n");

    for (i = 0; strlen(dw[i]) > 0; i++) {
        if (vogal(dw[i][0])) {
            printf("%s", dw[i]);
            printf(" ");
        }
        else {
            printf("%s", dw[i]);
        }
    }
    printf("\n");

    return 0;
}