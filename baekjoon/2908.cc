#include <cstdio>

using namespace std;

int main() {
    char a[4], b[4];
    bool ab;
    scanf("%s %s", a, b);
    for (int i = 0; i < 3; i++) {
        if (a[2-i] < b[2-i]) {
            ab = true;
            break;
        } else if (a[2-i] > b[2-i]) {
            ab = false;
            break;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (ab)
            putchar(b[2-i]);
        else
            putchar(a[2-i]);
    }

    return 0;
}
