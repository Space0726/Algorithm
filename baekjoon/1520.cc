#include <iostream>
#include <queue>

using namespace std;

int N, M, map[500][500], ans;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs() {
    int x, y, xx, yy, cnt = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            x = q.front().first, y = q.front().second; q.pop();
            if (x == N-1 && y == M-1) { ++ans; continue; }
            for (int k = 0; k < 4; ++k) {
                xx = x + dx[k], yy = y + dy[k];
                if (xx == -1 || xx == N || yy == -1 || yy == M || map[x][y] <= map[xx][yy])
                    continue;
                q.push({xx, yy});
            }
        }
        ++cnt;
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &map[i][j]);
    bfs();
    printf("%d", ans);
    return 0;
}
