#include <iostream>

using namespace std;

struct Pos {
    int x;
    int y;
};

int H, W, f, r;
Pos q[1000000];
char sand[1000][1000];
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};

inline bool is_wall(int x, int y) {
    return x < 0 || x >= H || y < 0 || y >= W;
}

int wave() {
    Pos tmp;
    int cnt = 0, xx, yy, i, j, size;
    bool end;
    while (r != f) {
        size = f - r;
        end = true;
        for (i = 0; i < size; ++i) {
            tmp = q[++r];
            for (j = 0; j < 8; ++j) {
                xx = tmp.x + dx[j];
                yy = tmp.y + dy[j];
                if (is_wall(xx, yy) || sand[xx][yy] < '1')
                    continue;
                --sand[xx][yy];
                if (sand[xx][yy] == '0') {
                    end = false;
                    q[++f] = {xx, yy};
                }
            }
        }
        if (end)
            break;
        ++cnt;
    }
    return cnt;
}

void init() {
    scanf("%d%d", &H, &W);
    int xx, yy, i, j;
    f = -1;
    r = -1;
    for (i = 0; i < H; ++i) {
        scanf("%s", sand[i]);
        for (j = 0; j < W; ++j) {
            if (sand[i][j] == '.')
                q[++f] = {i, j};
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        init();
        printf("#%d %d\n", test_case, wave());
    }
    return 0;
}
