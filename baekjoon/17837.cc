#include <iostream>
#include <vector>

using namespace std;

int N, K, ans, board[12][12], state[12][12][11];
struct Unit { int x, y, idx, dir; Unit(){} };
vector<Unit> units;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void move() {
    int xx, yy, x, y, dir, idx, mv_size;
    for (ans = 1; ans <= 1000; ++ans) {
        for (int i = 0; i < K; ++i) {
            x = units[i].x, y = units[i].y; dir = units[i].dir; idx = units[i].idx;
            xx = x + dx[dir], yy = y + dy[dir];
            if (xx < 0 || xx >= N || yy < 0 || yy >= N || board[xx][yy] == 2) {
                units[i].dir = dir = dir & 1 ? dir - 1 : dir + 1;
                xx = x + dx[dir], yy = y + dy[dir];
                if (xx < 0 || xx >= N || yy < 0 || yy >= N || board[xx][yy] == 2)
                    continue;
                else if (board[xx][yy] == 1) {
                    mv_size = state[x][y][0] - idx + 1;
                    for (int j = idx + mv_size - 1; j >= idx; --j) {
                        int cur = state[x][y][j];
                        state[xx][yy][++state[xx][yy][0]] = cur;
                        if (state[xx][yy][0] >= 4) return;
                        units[cur].x = xx, units[cur].y = yy, units[cur].idx = state[xx][yy][0];
                        state[x][y][j] = 0; --state[x][y][0];
                    }
                } else {
                    mv_size = state[x][y][0] - idx + 1;
                    for (int j = idx; j < idx + mv_size; ++j) {
                        int cur = state[x][y][j];
                        state[xx][yy][++state[xx][yy][0]] = cur;
                        if (state[xx][yy][0] >= 4) return;
                        units[cur].x = xx, units[cur].y = yy, units[cur].idx = state[xx][yy][0];
                        state[x][y][j] = 0; --state[x][y][0];
                    }
                }
            } else if (board[xx][yy] == 1) {
                mv_size = state[x][y][0] - idx + 1;
                for (int j = idx + mv_size - 1; j >= idx; --j) {
                    int cur = state[x][y][j];
                    state[xx][yy][++state[xx][yy][0]] = cur;
                    if (state[xx][yy][0] >= 4) return;
                    units[cur].x = xx, units[cur].y = yy, units[cur].idx = state[xx][yy][0];
                    state[x][y][j] = 0; --state[x][y][0];
                }
            } else {
                mv_size = state[x][y][0] - idx + 1;
                for (int j = idx; j < idx + mv_size; ++j) {
                    int cur = state[x][y][j];
                    state[xx][yy][++state[xx][yy][0]] = cur;
                    if (state[xx][yy][0] >= 4) return;
                    units[cur].x = xx, units[cur].y = yy, units[cur].idx = state[xx][yy][0];
                    state[x][y][j] = 0; --state[x][y][0];
                }
            }
        }
    }
    if (ans == 1001) ans = -1;
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &board[i][j]);
    units = vector<Unit>(K);
    for (int i = 0; i < K; ++i) {
        scanf("%d%d%d", &units[i].x, &units[i].y, &units[i].dir);
        --units[i].x; --units[i].y; --units[i].dir;
        units[i].idx = ++state[units[i].x][units[i].y][0];
        state[units[i].x][units[i].y][units[i].idx] = i;
    }
    move();
    printf("%d", ans);
    return 0;
}
