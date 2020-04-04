#include <iostream>

using namespace std;

int main() {
    int a = 1, b = 1, t, n;
    scanf("%d", &n);
    while (--n) {
        t = b % 10007;
        b += a;
        a = t;
    }
    printf("%d", b % 10007);
    return 0;
}
