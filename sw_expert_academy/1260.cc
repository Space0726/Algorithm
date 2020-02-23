#include <iostream>

using namespace std;

typedef struct {
    int x;
    int y;
} Pos;

typedef struct {
    int r;
    int c;
} Matrix;

int n, mat_num;
int map[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
Matrix mats[20];

void swap(int a, int b) {
    Matrix t = mats[a];
    mats[a] = mats[b];
    mats[b] = t;
}

int bfs() {
    int xx, yy, min_r, max_r, min_c, max_c, f, r;
    int candidates[100] = {0,};
    bool visited[100][100] = {false,};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j] && map[i][j]) {
                min_r = n; max_r = -1; min_c = n; max_c = -1;
                Pos q[10000];
                Pos tmp;
                tmp.x = i; tmp.y = j;
                f = 0; r = 0;
                q[r++] = tmp;
                while (f != r) {
                    if (min_r > q[f].x) min_r = q[f].x;
                    if (max_r < q[f].x) max_r = q[f].x;
                    if (min_c > q[f].y) min_c = q[f].y;
                    if (max_c < q[f].y) max_c = q[f].y;
                    for (int k = 0; k < 4; ++k) {
                        xx = q[f].x + dx[k];
                        yy = q[f].y + dy[k];
                        if (xx < 0 || xx >= n || yy < 0 || yy >= n || visited[xx][yy] || !map[xx][yy])
                            continue;
                        visited[xx][yy] = true;
                        tmp.x = xx; tmp.y = yy;
                        q[r++] = tmp;
                    }
                    ++f;
                }
                Matrix t;
                t.r = max_r - min_r + 1; t.c = max_c - min_c + 1;
                mats[mat_num++] = t;
                ++candidates[t.r - 1];
                ++candidates[t.c - 1];
            }
        }
    }

    int start[2] = {0,};
    for (int i = 0; i < 100; ++i) {
        if (candidates[i] & 1) {
            if (start[0]) {
                start[1] = i;
                break;
            } else {
                start[0] = i;
            }
        }
    }
    for (int i = 0; i < mat_num; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (start[j] == mats[i].r - 1) {
                start[0] = i;
                goto start;
            }
        }
    }
start:
    return start[0];
}

bool dfs(int k) {
    if (k == mat_num)
        return true;
    for (int i = k; i < mat_num; ++i) {
        swap(i, k);
        if (mats[k - 1].c == mats[k].r && (dfs(k + 1)))
            return true;
        swap(i, k);
    }
    return false;
}

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int calc_min_mult() {
    int dp[20][20] = {0,}, min_mult;
    for (int i = 1; i < mat_num; ++i) {
        for (int j = i; j < mat_num; ++j) {
            min_mult = 1e31;
            for (int k = j - i; k < j; ++k)
                min_mult = min(min_mult, dp[j-i][k] + dp[k+1][j] + mats[j-i].r * mats[k+1].r * mats[j].c);
            dp[j-i][j] = min_mult;
        }
    }
    return dp[0][mat_num - 1];
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        scanf("%d", &n);
        mat_num = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &map[i][j]);
        swap(bfs(), 0);
        dfs(1);
        printf("#%d %d\n", test_case, calc_min_mult());
    }
    return 0;
}
