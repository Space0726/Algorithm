#include <iostream>

using namespace std;

int n, m, r, c, l, num, map[50][50];
int dx[7][5] = {
    {4, 1, 0, -1, 0},
    {2, 1, -1, 0, 0},
    {2, 0, 0, 0, 0},
    {2, -1, 0, 0, 0},
    {2, 1, 0, 0, 0},
    {2, 1, 0, 0, 0},
    {2, -1, 0, 0, 0}
};
int dy[7][5] = {
    {4, 0, 1, 0, -1},
    {2, 0, 0, 0, 0},
    {2, 1, -1, 0, 0},
    {2, 0, 1, 0, 0},
    {2, 0, 1, 0, 0},
    {2, 0, -1, 0, 0},
    {2, 0, -1, 0, 0}
};

bool is_wall(int a, int b) {
    return a < 0 || a >= n || b < 0 || b >= m;
}

void bfs() {
    int q[2500] = {0,}, f = 0, r_ = 0, cnt = l, x, y, xx, yy, tmp, cx, cy;
    bool visited[50][50] = {false,}, cross;
    q[r_++] = r*m + c;
    visited[r][c] = true;
    while (--cnt) {
        tmp = r_;
        while (f != tmp) {  
            x = q[f] / m;
            y = q[f] % m;
            for (int i = 1; i <= dx[map[x][y] - 1][0]; ++i) {
                xx = x + dx[map[x][y] - 1][i];
                yy = y + dy[map[x][y] - 1][i];
                if (is_wall(xx, yy) || !map[xx][yy] || visited[xx][yy])
                    continue;
                cross = false;
                for (int j = 1; j <= dx[map[xx][yy] - 1][0]; ++j) {
                    cx = xx + dx[map[xx][yy] - 1][j];
                    cy = yy + dy[map[xx][yy] - 1][j];
                    if (is_wall(cx, cy))
                        continue;
                    if (cx == x && cy == y) {
                        cross = true;
                        break;
                    }
                }
                if (cross) {
                    visited[xx][yy] = true;
                    ++num;
                    q[r_++] = xx*m + yy;
                }
            }
            ++f;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        scanf("%d%d%d%d%d", &n, &m, &r, &c, &l);
        num = 1;
        for (int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                scanf("%d", &map[i][j]);
        bfs();
        printf("#%d %d\n", test_case, num);
    }
    return 0;
}
