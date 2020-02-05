#include <stdio.h>

void cpy(char *a, char *b) {
    while (*a != '\0') {
        *a = *b;
        ++b;
        ++a;
    }
    *a = '\0';
}
int main() {
    char a[4] = "abc";
    char b[4];
    for (int i = 0; i < 3; i++)
        printf("%c\n", a[i]);
    cpy(a, b);
    for (int i = 0; i < 3; i++)
        printf("%c %c\n", a[i], b[i]);

    return 0;
}
