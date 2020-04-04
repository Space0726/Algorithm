#include <iostream>

using namespace std;

int dp[1001][10];

int calc(int n, int d) {
    if (n == 1) return 1;
    if (dp[n][d]) return dp[n][d];
    int ret = 0;
    for (int i = 0; i <= d; ++i)
        ret = (ret + calc(n-1, i)) % 10007;
    return dp[n][d] = ret;
}

int main() {
    int N, ans = 0;
    scanf("%d", &N);
    for (int i = 0; i < 10; ++i)
        ans = (ans + calc(N, i)) % 10007;
    printf("%d", ans);
    return 0;
}
