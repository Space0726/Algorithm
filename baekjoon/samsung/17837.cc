#include <iostream>
#include <vector>

using namespace std;

struct Unit {
    int r;
    int c;
    int dir;
    int upper[10] = {0,};
    Unit(){}
    Unit(int a, int b, int c_): r(a), c(b), dir(c_) {}
    void move(int, int);
    void reverse(int, int);
};

int n, k;
vector<vector<int>> board;
vector<Unit> units;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void Unit::move(int x, int y) {
    r = x;
    c = y;
    for (int i = 0; i < 10; ++i) {
        if (upper[i] == -1)
            break;
        units[upper[i]].r = x;
        units[upper[i]].c = y;
    }
    // 이동하려는 곳에 말이 있으면 업히기
}

void Unit::reverse(int k, int n) {
    if (upper[k] == -1) {
        upper[k] = n;
        return;
    }
    for (int i = k; i < 10; ++i) {
        if (upper[i] == -1)
            break;
        units[upper[i]].reverse(i, n);
    }
}

bool is_wall(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

int main() {
    int a, b, c_, ans = 0;
    scanf("%d%d", &n, &k);
    board = vector<vector<int>>(n, vector<int>(n));
    units = vector<Unit>();
    for (int i = 0; i < k; ++i) {
        scanf("%d%d%d", &a, &b, &c_);
        units.push_back(Unit(a - 1, b - 1, c_ - 1));
    }
    int xx, yy;
    while (++ans <= 1000) {
        for (int i = 0; i < k; ++i) {
            xx = units[i].r + dx[units[i].dir];
            yy = units[i].c + dy[units[i].dir];
            if (is_wall(xx, yy) || board[xx][yy] == 2) {
                units[i].dir = units[i].dir & 1 ? units[i].dir - 1 : units[i].dir + 1;
                xx = units[i].r + dx[units[i].dir];
                yy = units[i].c + dy[units[i].dir];
                if (is_wall(xx, yy) || map[xx][yy] == 2)
                    continue;
                uints.move(xx, yy);
            } else if (board[xx][yy] == 1) {
                units[i].move(xx, yy);
                units[i].reverse(0, 0);
            } else {
                units[i].move(xx, yy);
            }
        }
    }
    printf("%d", ans > 1000 ? -1 : ans);
    return 0;
}
