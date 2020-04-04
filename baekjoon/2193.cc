#include <iostream>

using namespace std;

int main() {
    int N;
    long long a = 0, b = 1, t;
    scanf("%d", &N);
    while (--N) {
        t = b;
        b += a;
        a = t;
    }
    printf("%lld", b);
    return 0;
}
