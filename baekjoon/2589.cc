#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int r, c, max_depth = 0;
char map[50][50];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int x, int y) {
    int depth[50][50] = { 0, };
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(r, vector<bool>(c));
    q.push(make_pair(x, y));
    int xx, yy, depth_cnt = 1;
    depth[x][y] = depth_cnt;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        if (max_depth < depth[x][y])
            max_depth = depth[x][y];
        if (!visited[x][y]) {
            visited[x][y] = true;
            for (int i = 0; i < 4; i++) {
                xx = x + dx[i];
                yy = y + dy[i];
                if (xx < 0 || xx >= r || yy < 0 || yy >= c)
                    continue;
                if (!visited[xx][yy] && map[xx][yy] == 'L') {
                    q.push(make_pair(xx, yy));
                    if (depth[xx][yy] == 0 || depth[xx][yy] > depth[x][y] + 1)
                        depth[xx][yy] = depth[x][y] + 1;
                }
            }
        }
        q.pop();
    }
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 'L') {
                bfs(i, j);
            }
        }
    }
    printf("%d\n", max_depth - 1);
}