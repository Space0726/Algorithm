#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> dp, colors;

int main() {
    scanf("%d", &N);
    colors = vector<vector<int>>(N, vector<int>(3));
    for (int i = 0; i < N; ++i)
        scanf("%d%d%d", &colors[i][0], &colors[i][1], &colors[i][2]);
    int ans = 2e9, i, j;
    for (i = 0; i < 3; ++i) {
        dp = vector<vector<int>>(3, vector<int>(N));
        for (j = 0; j < 3; ++j) {
            if (j == i) {
                dp[j][0] = colors[0][j];
                continue;
            }
            dp[j][0] = 2e9;
        }
        for (j = 1; j < N; ++j) {
            dp[0][j] = colors[j][0] + min(dp[1][j-1], dp[2][j-1]);
            dp[1][j] = colors[j][1] + min(dp[0][j-1], dp[2][j-1]);
            dp[2][j] = colors[j][2] + min(dp[0][j-1], dp[1][j-1]);
        }
        for (j = 0; j < 3; ++j) {
            if (i == j) continue;
            ans = min(ans, dp[j][N-1]);
        }
    }
    printf("%d", ans);
    return 0;
}
