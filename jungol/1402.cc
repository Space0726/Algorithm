#include <cstdio>

using namespace std;

int main() {
    int N, K, i, cnt = 0;
    scanf("%d %d", &N, &K);
    for (i = 1; i <= N; i++) {
        if (!(N%i)) {
            if (++cnt == K) {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    putchar('0');

    return 0;
}
