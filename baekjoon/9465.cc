#include <iostream>

using namespace std;

int N, sticker[2][100000], dp[100000][2];

int calc(int n, int d) {
    if (n == 0) return sticker[d][0];
    else if (n == 1) return sticker[d^1][0] + sticker[d][1];
    if (dp[n][d] > -1) return dp[n][d];
    return dp[n][d] = sticker[d][n] + max(calc(n-1, d^1), calc(n-2, d^1));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            scanf("%d", &sticker[0][i]);
        for (int i = 0; i < N; ++i)
            scanf("%d", &sticker[1][i]);
        for (int i = 0; i < N; ++i)
            dp[i][0] = dp[i][1] = -1;
        printf("%d\n", max(calc(N-1, 0), calc(N-1, 1)));
    }
    return 0;
}
