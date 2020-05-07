#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, R, C, L, ans, board[50][50];
int dx[8][5] = {
    {0, 0, 0, 0, 0},
    {4, -1, 0, 1, 0},
    {2, -1, 1, 0, 0},
    {2, 0, 0, 0, 0},
    {2, -1, 0, 0, 0},
    {2, 0, 1, 0, 0},
    {2, 1, 0, 0, 0},
    {2, 0, -1, 0, 0}
};
int dy[8][5] = {
    {0, 0, 0, 0, 0},
    {4, 0, 1, 0, -1},
    {2, 0, 0, 0, 0},
    {2, 1, -1, 0, 0},
    {2, 0, 1, 0, 0},
    {2, 1, 0, 0, 0},
    {2, 0, -1, 0, 0},
    {2, -1, 0, 0, 0}
};

bool cross_check(int x, int y, int xx, int yy) {
    int dir = board[x][y], nx, ny;
    for (int i = 1; i <= dx[dir][0]; ++i) {
        nx = x + dx[dir][i], ny = y + dy[dir][i];
        if (nx == -1 || nx == N || ny == -1 || ny == M) continue;
        if (xx == nx && yy == ny) return true;
    }
    return false;
}

void find() {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M));
    int x, y, xx, yy, dir, size;

    q.push({R, C});
    visited[R][C] = true;

    for (int l = 1; l < L; ++l) {
        size = q.size();
        for (int t = 0; t < size; ++t) {
            x = q.front().first, y = q.front().second; q.pop();
            dir = board[x][y];
            for (int i = 1; i <= dx[dir][0]; ++i) {
                xx = x + dx[dir][i], yy = y + dy[dir][i];
                if (xx == -1 || xx == N || yy == -1 || yy == M || visited[xx][yy] || !board[xx][yy])
                    continue;
                if (!cross_check(xx, yy, x, y)) continue;

                visited[xx][yy] = true;
                q.push({xx, yy});
                ++ans;
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d%d%d%d%d", &N, &M, &R, &C, &L);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                scanf("%d", &board[i][j]);
        ans = 1;
        find();
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
