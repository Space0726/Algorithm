#include <iostream>

using namespace std;

int dp[101][10];

long long calc(int n, int d) {
    if (n == 1 && d == 0) return 0;
    if (dp[n][d]) return dp[n][d];
    if (d == 0) return dp[n][d] = calc(n-1, d+1);
    else if (d == 9) return dp[n][d] = calc(n-1, d-1);
    return dp[n][d] = (calc(n-1, d-1) + calc(n-1, d+1)) % 1000000000;
}

int main() {
    int N;
    long long ans = 0;
    scanf("%d", &N);
    for (int i = 1; i < 10; ++i)
        dp[1][i] = 1;
    for (int i = 0; i < 10; ++i)
        ans = (ans + calc(N, i)) % 1000000000;
    printf("%lld", ans);
    return 0;
}
