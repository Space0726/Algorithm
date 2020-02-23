#include <iostream>

using namespace std;

struct Pos {
    int x;
    int y;
    Pos(){}
    Pos(int a, int b): x(a), y(b) {}
};

int n, k, max_len, map[8][8], visited[8][8] = {0,};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool is_wall(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

void dfs(int x, int y, int depth) {
    if (depth > max_len)
        max_len = depth;
    int xx, yy;
    for (int a = 0; a < 4; ++a) {
        xx = x + dx[a];
        yy = y + dy[a];
        if (is_wall(xx, yy) || visited[xx][yy])
            continue;
        if (map[xx][yy] < map[x][y]) {
            visited[xx][yy] = 1;
            dfs(xx, yy, depth + 1);
            visited[xx][yy] = 0;
        }
    }
}

int find_submit(Pos *stack) {
    int t = -1, max_height = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (max_height < map[i][j])
                max_height = map[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (max_height == map[i][j])
                stack[++t] = Pos(i, j);
    return t;
}

void dig() {
    int prev_cnt, cnt, t;
    Pos stack[64];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            prev_cnt = 0;
            for (int b = 0; b < 4; ++b) {
                if (is_wall(i + dx[b], j + dy[b]))
                    continue;
                if (map[i][j] >= map[i + dx[b]][j + dy[b]])
                    ++prev_cnt;
            }
            for (int a = 1; a <= k; ++a) {
                cnt = 0;
                map[i][j] -= a;
                for (int b = 0; b < 4; ++b) {
                    if (is_wall(i + dx[b], j + dy[b]))
                        continue;
                    if (map[i][j] >= map[i + dx[b]][j + dy[b]])
                        ++cnt;
                }
                if (prev_cnt != cnt) {
                    t = find_submit(stack);
                    while (t != -1) {
                        visited[stack[t].x][stack[t].y] = 1;
                        dfs(stack[t].x, stack[t].y, 1);
                        visited[stack[t].x][stack[t--].y] = 0;
                    }
                }
                map[i][j] += a;
                if (prev_cnt == 0 && cnt == 0)
                    break;
                prev_cnt = cnt;
            }
        }
    }
}

void not_dig() {
    Pos stack[64];
    int t = find_submit(stack);
    while (t != -1) {
        visited[stack[t].x][stack[t].y] = 1;
        dfs(stack[t].x, stack[t].y, 1);
        visited[stack[t].x][stack[t--].y] = 0;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        scanf("%d%d", &n, &k);
        max_len = 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &map[i][j]);
        not_dig(); dig();
        printf("#%d %d\n", test_case, max_len);
    }
    return 0;
}
