#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, D, archer[3], max_ans;
vector<vector<int>> board;
int dx[3] = {0, -1, 0};
int dy[3] = {-1, 0, 1};

pair<int, int> attack(vector<vector<int>>& v, int m) {
    int x, y, xx, yy, size;
    vector<vector<bool>> visited(N, vector<bool>(M));
    queue<pair<int, int>> q;
    q.push({N-1, m});
    visited[N-1][m] = true;
    for (int i = 1; i <= D; ++i) {
        size = q.size();
        for (int j = 0; j < size; ++j) {
            x = q.front().first, y = q.front().second; q.pop();
            if (v[x][y]) return {x, y};
            for (int k = 0; k < 3; ++k) {
                xx = x + dx[k], yy = y + dy[k];
                if (xx < 0 || yy < 0 || yy >= M || visited[xx][yy])
                    continue;
                q.push({xx, yy});
                visited[xx][yy] = true;
            }
        }
    }
    return {-1, -1};
}

bool move(vector<vector<int>>& v) {
    bool ret = false;
    for (int i = 0; i < M; ++i)
        for (int j = N-1; j >= 0; --j)
            if (v[j][i]) {
                ret = true;
                v[j+1][i] = v[j][i];
                v[j][i] = 0;
            }
    return ret;
}

void play() {
    int killed = 0;
    vector<vector<int>> cp = board;
    do {
        vector<pair<int, int>> target;
        for (int i = 0; i < 3; ++i) {
            pair<int, int> tmp = attack(cp, archer[i]);
            if (tmp.first != -1) target.push_back(tmp);
        }
        for (pair<int, int>& p: target)
            if (cp[p.first][p.second]) {
                ++killed;
                cp[p.first][p.second] = 0;
            }
    } while (move(cp));
    if (max_ans < killed) max_ans = killed;
}

void comb(int k, int s) {
    if (k == 3) {
        play();
    } else {
        for (int i = s; i <= M + (k - 3); ++i) {
            archer[k] = i;
            comb(k + 1, i + 1);
        }
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &D);
    board = vector<vector<int>> (N+1, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &board[i][j]);
    comb(0, 0);
    printf("%d", max_ans);
    return 0;
}
