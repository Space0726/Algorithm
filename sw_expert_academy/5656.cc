#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, W, H, p[4], ans;
int dx[4] = {0, 1, 0 ,-1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int>> board, v;
struct Node {
    int x, y, range;
    Node() {}
    Node(int a, int b, int c): x(a), y(b), range(c) {}
};

void del_block(int sx, int sy) {
    queue<Node> q;
    int x, y, xx, yy, range;
    q.push({sx, sy, v[sx][sy]});
    v[sx][sy] = 0;
    while (!q.empty()) {
        x = q.front().x, y = q.front().y;
        range = q.front().range; q.pop();
        if (range == 1) continue;
        for (int dir = 0; dir < 4; ++dir) {
            for (int k = 1; k < range; ++k) {
                xx = x + k*dx[dir], yy = y + k*dy[dir];
                if (xx < 0 || xx >= H || yy < 0 || yy >= W) break;
                if (v[xx][yy] == 0) continue;
                else if (v[xx][yy] == 1) { v[xx][yy] = 0; continue; }
                else { q.push({xx, yy, v[xx][yy]}); v[xx][yy] = 0; }
            }
        }
    }
}

void move_down() {
    for (int i = 0; i < W; ++i)
        for (int j = H-2; j >= 0; --j) {
            if (v[j][i] && !v[j+1][i]) {
                int h = j+1;
                while (h < H && !v[h][i]) ++h;
                v[h-1][i] = v[j][i];
                v[j][i] = 0;
            }
        }
}

int count_block() {
    int ret = 0;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (v[i][j]) ++ret;
    return ret;
}

void start() {
    v = board;
    for (int i = 0; i < N; ++i) {
        if (!v[H-1][p[i]]) continue;
        for (int j = 0; j < H; ++j)
            if (v[j][p[i]]) { del_block(j, p[i]); break; }
        move_down();
    }
    int sum = count_block();
    if (ans > sum) ans = sum;
}

void perm(int k) {
    if (k == N) {
        if (ans == 0) return;
        start();
    } else {
        for (int i = 0; i < W; ++i) {
            p[k] = i;
            perm(k + 1);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        ans = 2e9;
        scanf("%d%d%d", &N, &W, &H);
        board = vector<vector<int>> (H, vector<int>(W));
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                scanf("%d", &board[i][j]);
        perm(0);
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
