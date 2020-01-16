#include <cstdio>

using namespace std;

int main() {
    int max_n = 0, n, t, i;
    int fib_0[41], fib_1[41];
    fib_0[0] = 1; fib_0[1] = 0;
    fib_1[0] = 0; fib_1[1] = 1;

    scanf("%d", &t);
    int tc[t];
    for (i = 0; i < t; i++) {
        scanf("%d", &tc[i]);
        if (max_n < tc[i])
            max_n = tc[i];
    }

    for (i = 2; i <= max_n; i++) {
        fib_0[i] = fib_0[i-1] + fib_0[i-2];
        fib_1[i] = fib_1[i-1] + fib_1[i-2];
    }

    for (i = 0; i < t; i++)
        printf("%d %d\n", fib_0[tc[i]], fib_1[tc[i]]);

    return 0;
}
