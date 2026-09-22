#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;
    Date birthday;
    char name[200];
} Student;

int ComparaDataNasc(Student s1, Student s2) {
    if (s1.birthday.year != s2.birthday.year)
        return s1.birthday.year < s2.birthday.year;

    if (s1.birthday.month != s2.birthday.month)
        return s1.birthday.month < s2.birthday.month;

    return s1.birthday.day < s2.birthday.day;
}

void swap(Student *s1, Student *s2) {
    Student tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

void bubble_sort(Student *s, int n) {
    int i, c;
    do {
        c = 0;
        for (i = 0; i < n - 1; i++) {
            if (ComparaDataNasc(s[i], s[i + 1])) {
                swap(&s[i], &s[i + 1]);
                c = 1;
            }
        }
    }
    while (c != 0);
}

int main(void) {
    int n;

    scanf("%d", &n);

    Student *s = (Student *)malloc(n * sizeof(Student));

    int i;
    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d %[^\n]%*c",
              &s[i].id,
              &s[i].birthday.day,
              &s[i].birthday.month,
              &s[i].birthday.year,
              s[i].name);
    }

    bubble_sort(s, n);

    for (i = 0; i < n; i++) {
        printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n",
               s[i].id,
               s[i].name,
               s[i].birthday.day,
               s[i].birthday.month,
               s[i].birthday.year);
    }

    free(s);

    return 0;
}