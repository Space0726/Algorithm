#include <iostream>
#include <vector>
#define MAX_VALUE 2000000000

using namespace std;

int N, M;
vector<vector<int>> map, partial_sum;
vector<vector<vector<vector<int>>>> dp;

int dfs(int y, int x, int h, int w) {
    if (w == 1 && h == 1) return 0;
    if (dp[y][x][h][w] != MAX_VALUE) return dp[y][x][h][w];
    int sum = 0, i, j, sum3;
    // 기존 덩어리의 건포도 개수
    // for (i = y; i < y + h; ++i)
        // for (j = x; j < x + w; ++j)
            // sum += map[i][j];
    for (i = y; i < y + h; ++i) {
        if (x - 1 >= 0)
            sum += partial_sum[i][x + w - 1] - partial_sum[i][x - 1];
        else
            sum += partial_sum[i][x + w - 1];
    }
    // 가로로 나누어서 최소비용 구하기
    for (i = 1; i < h; ++i) {
        // 위쪽 비용
        if (dp[y][x][i][w] == MAX_VALUE)
            dp[y][x][i][w] = dfs(y, x, i, w);
        // 아래쪽 비용
        if (dp[y + i][x][h - i][w] == MAX_VALUE)
            dp[y + i][x][h - i][w] = dfs(y + i, x, h - i, w);
        sum3 = sum + dp[y][x][i][w] + dp[y + i][x][h - i][w];
        dp[y][x][h][w] = dp[y][x][h][w] < sum3 ? dp[y][x][h][w] : sum3;
    }
    // 세로로 나누어서 최소비용 구하기
    for (i = 1; i < w; ++i) {
        // 왼쪽 비용
        if (dp[y][x][h][i] == MAX_VALUE)
            dp[y][x][h][i] = dfs(y, x, h, i);
        // 오른쪽 비용
        if (dp[y][x + i][h][w - i] == MAX_VALUE)
            dp[y][x + i][h][w - i] = dfs(y, x + i, h, w - i);
        sum3 = sum + dp[y][x][h][i] + dp[y][x + i][h][w - i];
        dp[y][x][h][w] = dp[y][x][h][w] < sum3 ? dp[y][x][h][w] : sum3;
    }
    return dp[y][x][h][w];
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d%d", &N, &M);
        map = vector<vector<int>>(N, vector<int>(M));
        partial_sum = vector<vector<int>>(N, vector<int>(M));
        dp = vector<vector<vector<vector<int>>>>(
                N + 1, vector<vector<vector<int>>>(
                M + 1, vector<vector<int>>(
                N + 1, vector<int>(M + 1, MAX_VALUE))));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                scanf("%d", &map[i][j]);
        for (int i = 0; i < N; ++i) {
            partial_sum[i][0] = map[i][0];
            for (int j = 1; j < M; ++j)
                partial_sum[i][j] = partial_sum[i][j - 1] + map[i][j];
        }
        printf("#%d %d\n", test_case, dfs(0, 0, N, M));
    }
    return 0;
}
