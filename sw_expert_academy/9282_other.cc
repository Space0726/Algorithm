#include <iostream>
#include <vector>
#define MAX_VALUE 2000000000

using namespace std;

int N, M;
vector<vector<int>> map, partial_sum;

int dfs(int y, int x, int h, int w, int min_) {
    if (w == 1 && h == 1) return 0;
    int sum = 0, i, j, sum1, sum2, sum3;
    for (i = y; i < y + h; ++i) {
        if (x - 1 >= 0)
            sum += partial_sum[i][x + w - 1] - partial_sum[i][x - 1];
        else
            sum += partial_sum[i][x + w - 1];
    }
    for (i = 1; i < h; ++i) {
        // 위쪽 비용
        sum1 = dfs(y, x, i, w, min_);
        // 아래쪽 비용
        sum2 = dfs(y + i, x, h - i, w, min_);
        sum3 = sum + sum1 + sum2;
        min_ = min_ < sum3 ? min_ : sum3;
    }
    for (i = 1; i < w; ++i) {
        // 왼쪽 비용
        sum1 = dfs(y, x, h, i, min_);
        // 오른쪽 비용
        sum2 = dfs(y, x + i, h, w - i, min_);
        sum3 = sum + sum1 + sum2;
        min_ = min_ < sum3 ? min_ : sum3;
    }
    return min_;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d%d", &N, &M);
        map = vector<vector<int>>(N, vector<int>(M));
        partial_sum = vector<vector<int>>(N, vector<int>(M));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                scanf("%d", &map[i][j]);
        for (int i = 0; i < N; ++i) {
            partial_sum[i][0] = map[i][0];
            for (int j = 1; j < M; ++j)
                partial_sum[i][j] = partial_sum[i][j - 1] + map[i][j];
        }
        printf("#%d %d\n", test_case, dfs(0, 0, N, M, MAX_VALUE));
    }
    return 0;
}
