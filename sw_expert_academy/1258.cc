#include <iostream>

using namespace std;

typedef struct {
    int x;
    int y;
} Pos;

typedef struct {
    int r;
    int c;
    Pos tl;
    Pos br;
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

bool compare_matrix(int a, int b) {
    if (mats[a].r * mats[a].c == mats[b].r * mats[b].c)
        return mats[a].r < mats[b].r;
    return mats[a].r * mats[a].c < mats[b].r * mats[b].c;
}

void quick_sort(int left, int right) {
    if (left >= right)
        return;

    swap(left, (left + right) / 2);
    int i = left, j = right + 1;

    while (i < j) {
        while (compare_matrix(left, --j));
        while (i < j && !compare_matrix(left, ++i));
        if (i < j) swap(i, j);
    }

    swap(left, i);
    quick_sort(left, i - 1);
    quick_sort(i + 1, right);
}

void bfs() {
    int xx, yy, min_r, max_r, min_c, max_c, f, r;
    int visited[100][100] = {0,};
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
                    if (min_r > q[f].x)
                        min_r = q[f].x;
                    if (max_r < q[f].x)
                        max_r = q[f].x;
                    if (min_c > q[f].y)
                        min_c = q[f].y;
                    if (max_c < q[f].y)
                        max_c = q[f].y;
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
                t.tl.x = min_r; t.tl.y = min_c;
                t.br.x = max_r; t.br.y = max_c;
                t.r = max_r - min_r + 1; t.c = max_c - min_c + 1;
                mats[mat_num++] = t;
            }
        }
    }
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
        bfs();
        quick_sort(0, mat_num - 1);
        printf("#%d %d ", test_case, mat_num);
        for (int i = 0; i < mat_num; ++i)
            printf("%d %d ", mats[i].r, mats[i].c);
        putchar('\n');
    }
    return 0;
}
