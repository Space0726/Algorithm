#include <iostream>
#include <queue>

using namespace std;

struct Turn {
    int sec;
    char dir;
    Turn(int s, char d): sec(s), dir(d) {}
};

int N, K, L, board[101][101];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
queue<Turn> turns;
queue<pair<int, int>> body;

bool is_meet(int r, int c) {
    pair<int, int> tmp;
    for (int i = 0; i < body.size(); ++i) {
        tmp = body.front();
        if (r == tmp.first && c == tmp.second)
            return true;
        body.pop();
        body.push(tmp);
    }
    return false;
}

int main() {
    scanf("%d%d", &N, &K);
    int r, c, dir, ans = 0, x, y;
    char tmp;
    for (int i = 0; i < K; ++i) {
        scanf("%d%d", &r, &c);
        board[r][c] = 1;
    }
    scanf("%d", &L);
    for (int i = 0; i < L; ++i) {
        scanf("%d %c", &r, &tmp);
        turns.push(Turn(r, tmp));
    }
    r = c = 1, dir = 0;
    body.push({r, c});
    while (++ans) {
        x = r + dx[dir], y = c + dy[dir];
        if (x < 1 || x > N || y < 1 || y > N || !body.empty() && is_meet(x, y))
            break;
        r = x, c = y;
        body.push({r, c});
        if (board[r][c])
            board[r][c] = 0;
        else
            body.pop();
        if (!turns.empty() && ans == turns.front().sec) {
            dir = turns.front().dir == 'L' ? dir + 1 : dir - 1;
            if (dir == -1) dir = 3;
            else if (dir == 4) dir = 0;
            turns.pop();
        }
    }
    printf("%d", ans);
    return 0;
}
