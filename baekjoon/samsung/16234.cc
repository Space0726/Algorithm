#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

vector<vector<int>> v;
int n, l, r;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void print_v() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", v[i][j]);
        }
        puts("");
    }
    puts("");
}

int bfs() {
    int x = 0, y = 0, xx, yy, cnt, sum, move_cnt = 0;
    bool is_moved = true;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n));
    while (is_moved) {
        is_moved = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    visited = vector<vector<bool>>(n, vector<bool>(n));
                    q.push(make_pair(i, j));
                    cnt = 0;
                    sum = 0;
                    while (!q.empty()) {
                        x = q.front().first;
                        y = q.front().second;
                        if (!visited[x][y]) {
                            visited[x][y] = true;
                            ++cnt;
                            sum += v[x][y];
                            for (int i = 0; i < 4; i++) {
                                xx = x + dx[i];
                                yy = y + dy[i];
                                if (xx < 0 || xx >= n || yy < 0 || yy >= n)
                                    continue;
                                if (!visited[xx][yy] && 
                                        abs(v[x][y] - v[xx][yy]) >= l && abs(v[x][y] - v[xx][yy]) <= r)
                                    q.push(make_pair(xx, yy));
                            }
                        }
                        q.pop();
                    }

                    if (cnt <= 1)
                        continue;
                    int avg = sum / cnt;
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < n; j++)
                            if (visited[i][j]) {
                                v[i][j] = avg;
                                is_moved = true;
                            }
                    if (is_moved) {
                        ++move_cnt;
                        print_v();
                    }
                    else
                        return move_cnt;
                }
            }
        }
    }
}

int main() {
    freopen("input_16234.txt", "r", stdin);
    for (int test_case = 0; test_case < 5; test_case++) {
        int i, j;
        scanf("%d %d %d", &n, &l, &r);
        v = vector<vector<int>>(n, vector<int>(n));
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf(" %d", &v[i][j]);
        printf("%d\n", bfs());
    }

    return 0;
}
