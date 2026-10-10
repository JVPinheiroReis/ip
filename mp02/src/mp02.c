#include <stdio.h>

int get_string_size(char *s) {
    int size;
    for (size = 0; s[size] != '\0'; size++) {
    }

    return size;
}

void inverter(char *s) {
    int size = get_string_size(s);

    char tmp[10000 + 1];

    int i, j = 0;
    for (i = size - 1; i >= 0; i--) {
        tmp[j] = s[i];
        j++;
    }

    for (i = 0; i < size; i++) {
        s[i] = tmp[i];
    }
}

void deslocar(char *s, int n) {
    int i, c;
    for (i = 0; s[i] != '\0'; i++) {
        if ('a' <= s[i] && s[i] <= 'z') {
            c = s[i];

            c += n % 26;

            if (c < 'a') c += 26;
            if (c > 'z') c -= 26;

            s[i] = c;
        }

        if ('A' <= s[i] && s[i] <= 'Z') {
            c = s[i];

            c += n % 26;

            if (c < 'A') c += 26;
            if (c > 'Z') c -= 26;

            s[i] = c;
        }

        if ('0' <= s[i] && s[i] <= '9') {
            c = s[i];

            c += n % 10;

            if (c < '0') c += 10;
            if (c > '9') c -= 10;

            s[i] = c;
        }
    }
}

void trocarParesImpares(char *s) {
    int size = get_string_size(s);

    char tmp[10000 + 1];

    int i;
    if (size % 2 != 0) {
        for (i = 0; i < size - 2; i += 2) {
            tmp[i] = s[i];
            s[i] = s[i + 1];
            s[i + 1] = tmp[i];
        }
    }
    else {
        for (i = 0; i < size - 1; i += 2) {
            tmp[i] = s[i];
            s[i] = s[i + 1];
            s[i + 1] = tmp[i];
        }
    }
}

void inverterCaixa(char *s) {
    char c;

    int i;
    for (i = 0; s[i] != '\0'; i++) {
        c = s[i];

        if ('a' <= c && c <= 'z') s[i] += 'A' - 'a';
        if ('A' <= c && c <= 'Z') s[i] += 'a' - 'A';
    }
}

void rotacionar(char *s, int n) {
    int size = get_string_size(s);

    n %= size;

    char tmp[size];

    int i, j;
    for (i = 0; i < size; i++) {
        tmp[i] = s[i];
    }

    for (i = 0; i < size; i++) {
        j = i + n;

        if (j < 0) {
            j += size;
        }
        if (j > size - 1) {
            j -= size;
        }

        s[j] = tmp[i];
    }
}

void trocarMetades(char *s) {
    int size = get_string_size(s);

    char tmp;

    int i, j;
    for (i = 0; i < size / 2; i++) {
        j = size - size / 2 + i;

        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

int main(void) {
    int n;
    char s[10000 + 1] = "";

    scanf("%[^\n]%*c", s);

    int op;
    while (1) {
        scanf("%d", &op);

        switch (op) {
            case 1: inverter(s); break;
            case 2:
                scanf("%d", &n);
                deslocar(s, n);
                break;
            case 3: trocarParesImpares(s); break;
            case 4: inverterCaixa(s); break;
            case 5:
                scanf("%d", &n);
                rotacionar(s, n);
                break;
            case 6: trocarMetades(s); break;
            case 0: printf("%s\n", s); return 0;
            default: return 0;
        }
    }

    printf("%s\n", s);

    return 0;
}