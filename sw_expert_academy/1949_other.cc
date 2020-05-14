#include <iostream>
#include <vector>

using namespace std;

int N, K, map[8][8], ans, summit;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int, int>> start;
vector<vector<bool>> visited;

struct Node {
    int x, y, dist;
    Node() {}
    Node(int a, int b, int c): x(a), y(b), dist(c) {}
};

void find_start() {
    start = vector<pair<int, int>>();
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (map[i][j] == summit)
                start.push_back({i, j});
}

void dfs(int x, int y, int dist) {
    if (ans < dist) ans = dist;
    for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx == -1 || xx == N || yy == -1 || yy == N || visited[xx][yy] || map[x][y] <= map[xx][yy]) continue;
        visited[xx][yy] = true;
        dfs(xx, yy, dist+1);
        visited[xx][yy] = false;
    }
}

void find_ans() {
    for (pair<int, int>& s: start) {
        visited[s.first][s.second] = true;
        dfs(s.first, s.second, 1);
        visited[s.first][s.second] = false;
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 1; k <= K; ++k) {
                map[i][j] -= k;
                for (pair<int, int>& s: start) {
                    visited[s.first][s.second] = true;
                    dfs(s.first, s.second, 1);
                    visited[s.first][s.second] = false;
                }
                map[i][j] += k;
            }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        ans = 0;
        scanf("%d%d", &N, &K);
        visited = vector<vector<bool>>(N, vector<bool>(N));
        summit = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) {
                scanf("%d", &map[i][j]);
                if (summit < map[i][j]) summit = map[i][j];
            }
        find_start();
        find_ans();
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
