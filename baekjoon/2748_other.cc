#include <cstdio>

using namespace std;

int main() {
    int n;
    long long a[2];
    a[0] = 0;
    a[1] = 1;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        a[i%2] += a[(i+1)%2];
    printf("%lld", a[n%2]);

    return 0;
}
