#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

vector<vector<int>> v;
int n, l, r;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs() {
    int cnt, sum, move_cnt = 0, x, xx, y, yy, visited_cnt;
    while (1) {
        vector<vector<int>> visited(n, vector<int>(n));
        vector<int> avgs(n*n);
        visited_cnt = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    cnt = 0;
                    sum = 0;
                    while (!q.empty()) {
                        x = q.front().first;
                        y = q.front().second;
                        if (visited[x][y]) {
                            q.pop();
                            continue;
                        }
                        visited[x][y] = visited_cnt;
                        ++cnt;
                        sum += v[x][y];
                        for (int k = 0; k < 4; k++) {
                            xx = x + dx[k];
                            yy = y + dy[k];
                            if (xx < 0 || xx >= n || yy < 0 || yy >= n)
                                continue;
                            if (!visited[xx][yy] &&
                                    l <= abs(v[x][y] - v[xx][yy]) && abs(v[x][y] - v[xx][yy]) <= r) {
                                q.push(make_pair(xx, yy));
                            }
                        }
                        q.pop();
                    }
                    if (cnt > 1)
                        avgs[visited_cnt - 1] = sum / cnt;
                    ++visited_cnt;
                }
            }
        }
        int check_not_move = 0, max_visited = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (avgs[visited[i][j] - 1] > 0) {
                    v[i][j] = avgs[visited[i][j] - 1];
                    if (max_visited < visited[i][j])
                        max_visited = visited[i][j];
                } else {
                    ++check_not_move;
                }
            }
        }
        if (check_not_move == n*n)
            return move_cnt;
        else
            ++move_cnt;
    }
}

int main() {
    int i, j;
    scanf("%d %d %d", &n, &l, &r);
    v = vector<vector<int>>(n, vector<int>(n));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf(" %d", &v[i][j]);
    printf("%d\n", bfs());

    return 0;
}
