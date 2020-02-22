#include <cstdio>

using namespace std;

int main() {
    int n;
    long long temp;
    long long a = 0;
    long long b = 1;
    int cnt = 1;
    scanf("%d", &n);
    if (n > 0) {
        while (cnt != n) {
            temp = b;
            b = a + b;
            a = temp;
            ++cnt;
        }
        printf("%lld", b);
    } else
        printf("%lld", a);

    return 0;
}
