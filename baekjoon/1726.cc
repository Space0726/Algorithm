#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, map[100][100], ex, ey, edir;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

inline bool is_wall(int x, int y) { return x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 1; }

int bfs(int a, int b, int dir) {
    int x, y, cdir, xx, yy, cnt = -1, tx, ty;
    struct Step {
        int x, y, dir;
        Step() {}
        Step(int a, int b, int c): x(a), y(b), dir(c) {}
    };
    queue<Step> q;
    vector<vector<int>> visited(N, vector<int>(M));
    visited[a][b] |= (1 << dir);
    q.push({a, b, dir});
    while (!q.empty()) {
        ++cnt;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            x = q.front().x, y = q.front().y, cdir = q.front().dir; q.pop();
            if (x == ex && y == ey && cdir == edir) return cnt;
            for (int k = 1; k <= 3; ++k) {
                tx = x + k*dx[cdir], ty = y + k*dy[cdir];
                if (is_wall(tx, ty)) break;
                if (visited[tx][ty] & (1 << cdir)) continue;
                visited[tx][ty] |= (1 << cdir);
                q.push({tx, ty, cdir});
            }
            int n_dir = cdir + 1;
            if (n_dir > 3) n_dir = 0;
            if (!(visited[x][y] & (1 << (n_dir)))) {
                visited[x][y] |= (1 << n_dir);
                q.push({x, y, n_dir});
            }
            n_dir = cdir + 3;
            if (n_dir > 3) n_dir -= 4;
            if (!(visited[x][y] & (1 << (n_dir)))) {
                visited[x][y] |= (1 << n_dir);
                q.push({x, y, n_dir});
            }
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &map[i][j]);
    int x, y, dir;
    int cvt[5] = {0, 0, 2, 1, 3};
    scanf("%d%d%d%d%d%d", &x, &y, &dir, &ex, &ey, &edir);
    --x; --y; --ex; --ey; edir = cvt[edir];
    printf("%d", bfs(x, y, cvt[dir]));
    return 0;
}
