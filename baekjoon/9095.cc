#include <iostream>

using namespace std;

int T, n, ans, dp[11];

int calc(int p) {
    if (dp[p]) return dp[p];
    switch (p) {
        case 1: return 1;
        case 2: return 2;
        case 3: return 4;
        default: return dp[p] = calc(p-1) + calc(p-2) + calc(p-3);
    }
}

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d", &n);
        printf("%d\n", calc(n));
    }
    return 0;
}
