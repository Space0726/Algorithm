#include <iostream>
#include <vector>

using namespace std;

int N, M, x, y, K, board[20][20];
int d[4] = {0, 3, 2, 1};
int oppo[6] = {2, 3, 0, 1, 5, 4};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> cmd;

struct Node {
    int val = 0;
    vector<int> neighbor;
    int find(int target) {
        for (int i = 0; i < 4; ++i)
            if (target == neighbor[i])
                return i;
    }
    int get_next(int prev_num, int prev_dir, int dir) {
        return neighbor[(find(prev_num) + d[prev_dir] + dir) % 4];
    }
};

Node dice[6];

void init() {
    dice[0].neighbor = {3, 4, 1, 5};
    dice[1].neighbor = {0, 4, 2, 5};
    dice[2].neighbor = {1, 4, 3, 5};
    dice[3].neighbor = {2, 4, 0, 5};
    dice[4].neighbor = {0, 3, 2, 1};
    dice[5].neighbor = {0, 1, 2, 3};
}

int main() {
    scanf("%d%d%d%d%d", &N, &M, &x, &y, &K);
    cmd = vector<int>(K);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &board[i][j]);
    for (int i = 0; i < K; ++i)
        scanf("%d", &cmd[i]);
    init();
    int xx, yy, dir = 0, cur = 0, p_num = 3, p_dir = 0, t_num, t_dir;
    int cvt[5] = {0, 1, 3, 0, 2};
    for (int i = 0; i < K; ++i) {
        t_dir = dir;
        dir = cvt[cmd[i]];
        xx = x + dx[dir], yy = y + dy[dir];
        if (xx < 0 || xx >= N || yy < 0 || yy >= M) {
            dir = t_dir;
            continue;
        }
        x = xx, y = yy;
        t_num = cur;
        cur = dice[cur].get_next(p_num, p_dir, dir);
        p_num = t_num, p_dir = (dir + 2) % 4;
        if (board[x][y]) {
            dice[cur].val = board[x][y];
            board[x][y] = 0;
        } else {
            board[x][y] = dice[cur].val;
        }
        printf("%d\n", dice[oppo[cur]].val);
    }
    return 0;
}
