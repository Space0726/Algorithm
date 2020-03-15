#include <iostream>

#define MAX_LEN 100

using namespace std;

int N, map[MAX_LEN][MAX_LEN], memo[MAX_LEN][MAX_LEN], min_len;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

inline bool is_wall(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= N;
}

void greedy() {
    int x = 0, y = 0;
    while (1) {
        if (x == N-1 && y == N-1)
            return;
        if (is_wall(x + 1, y) && !is_wall(x, y + 1))
            min_len += map[x][++y];
        else if (!is_wall(x + 1, y) && is_wall(x, y + 1))
            min_len += map[++x][y];
        else {
            if (map[x+1][y] < map[x][y+1])
                min_len += map[++x][y];
            else
                min_len += map[x][++y];
        }
    }
}

void dfs(pair<int, int> pos) {
    int x, y, cur;
    for (int k = 0; k < 4; ++k) {
        x = pos.first + dx[k], y = pos.second + dy[k];
        if (is_wall(x, y))
            continue;
        cur = memo[pos.first][pos.second] + map[x][y];
        if (min_len < cur || cur >= memo[x][y])
            continue;
        memo[x][y] = cur;
        dfs({x, y});
    }
}

int main() {
    int T;
    char tmp;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf(" %c", &tmp);
                map[i][j] = tmp - '0';
                memo[i][j] = 2e9;
            }
        }
        min_len = 0;
        memo[0][0] = 0;
        greedy();
        dfs({0, 0});
        printf("#%d %d\n", test_case, memo[N-1][N-1]);
    }
    return 0;
}
