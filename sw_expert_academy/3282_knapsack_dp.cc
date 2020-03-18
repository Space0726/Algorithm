#include <iostream>

using namespace std;

int N, K, v[101], c[101], dp[101][1001];

inline int max(int a, int b) { return a > b ? a : b; }

void knapsack() {
    for (int i = 0; i <= N; ++i)
        dp[i][0] = 0;
    for (int i = 0; i <= K; ++i)
        dp[0][i] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            if (j < v[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j-v[i]] + c[i], dp[i-1][j]);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d%d", &N, &K);
        for (int i = 1; i <= N; ++i)
            scanf("%d%d", &v[i], &c[i]);
        knapsack();
        printf("#%d %d\n", test_case, dp[N][K]);
    }
    return 0;
}
