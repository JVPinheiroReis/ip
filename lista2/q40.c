#include <stdio.h>

struct tRacional {
    int a;
    int b;
};

int MDC(int a, int b) {
    a = a < 0 ? -a : a;

    if (b == 0) {
        return a;
    }
    return MDC(b, a % b);
}

struct tRacional racional(int a, int b) {
    struct tRacional r;

    r.a = a;
    r.b = b;

    return r;
}

struct tRacional negativo(struct tRacional r) {
    r.a = -r.a;

    return r;
}

struct tRacional soma(struct tRacional r1, struct tRacional r2) {
    struct tRacional r;
    int base = r1.b * r2.b;

    r1.a *= base / r1.b;
    r1.b *= base / r1.b;

    r2.a *= base / r2.b;
    r2.b *= base / r2.b;

    r.a = r1.a + r2.a;
    r.b = base;

    return r;
}

struct tRacional mult(struct tRacional r1, struct tRacional r2) {
    struct tRacional r;

    r.a = r1.a * r2.a;
    r.b = r1.b * r2.b;

    return r;
}

struct tRacional div(struct tRacional r1, struct tRacional r2) {
    struct tRacional r;

    r.a = r1.a * r2.b;
    r.b = r1.b * r2.a;

    return r;
}

void reduzFracao(struct tRacional *r) {
    int d = MDC(r->a, r->b);

    r->a /= d;
    r->b /= d;
}

int main(void) {
    char op;
    struct tRacional r, r1, r2;
    int a1, b1, a2, b2;

    while (scanf("%d %d %c %d %d", &a1, &b1, &op, &a2, &b2) != EOF) {
        r1 = racional(a1, b1);
        r2 = racional(a2, b2);

        switch (op) {
            case '+': r = soma(r1, r2); break;
            case '-': r = soma(r1, negativo(r2)); break;
            case '*': r = mult(r1, r2); break;
            case '/': r = div(r1, r2); break;
        }

        reduzFracao(&r);

        printf("%d %d\n", r.a, r.b);
    }

    return 0;
}