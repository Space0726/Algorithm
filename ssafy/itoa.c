#include <stdio.h>

int strlen(char p[]) {
    int res = 0
}

void strrev(char str[]) {
    int len = 0, i;
    char t;
    
    len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        t = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = t;
    }
}

void itoa(int x, char str[]) {
    int cnt = 0;
    int i = 0, y;
    while (1) {
        y = x % 10;
        str[i++] = y + '0';
        x /= 10;
        if (x == 0) break;
    }
    str[i] = '\0';
    strrev(str);    // Reverse
}

int main() {
    char ary[5];
    itoa(1234, ary);

    return 0;
}
