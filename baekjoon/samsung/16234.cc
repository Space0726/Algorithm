#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

int n, l, r;
vector<vector<int>> v;

int bfs() {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool(n));
    int x, y, xx, yy, cnt = 0, sum = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    q.push(make_pair(x, y));

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        if (!visited[x][y]) {
            ++cnt;
            sum += v[x][y];
            for (int i = 0; i < 4; i++) {
                xx = x + dx[i];
                yy = y + dy[i];
                if (xx < 0 || xx >= n || yy < 0 || yy >= n)
                    continue;
                if (!visited[xx][yy] && abs(v[x][y] - v[xx][yy]) <= r - l)
                    q.push(make_pair(xx, yy));
            }
        }
        q.pop();
    }
    // Needs cnt ==  0 Error Handling
    int avg = sum / cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j])
                v[i][j] = avg;
        }
    }
}

int main() {
    int i, j;
    scanf("%d %d %d", &n, &l, &r);
    v = vector<vector<int>>(n, vector<int>(n));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf(" %d", &v[i][j]);

    // for (auto a: v) {
        // for (auto b: a)
            // printf("%d ", b);
        // putchar('\n');
    // }

    return 0;
}
