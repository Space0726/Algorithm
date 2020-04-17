#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, blank, lab[50][50], ans = 2e9, virus_size;
vector<int> selected;
vector<pair<int, int>> virus;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void spread() {
    vector<vector<bool>> visited(N, vector<bool>(N));
    queue<pair<int, int>> q;
    int x, y, xx, yy, cnt = 0, size, time_ = 0;
    for (int i = 0; i < M; ++i) {
        q.push(virus[selected[i]]);
        visited[q.back().first][q.back().second] = true;
    }
    while (!q.empty()) {
        size = q.size();
        for (int i = 0; i < size; ++i) {
            x = q.front().first, y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; ++k) {
                xx = x + dx[k], yy = y + dy[k];
                if (xx < 0 || xx >= N || yy < 0 || yy >= N || visited[xx][yy] || lab[xx][yy] == 1)
                    continue;
                if (!lab[xx][yy]) ++cnt;
                visited[xx][yy] = true;
                q.push({xx, yy});
            }
        }
        ++time_;
        if (cnt == blank) break;
        if (time_ >= ans) return;
    }
    if (cnt == blank && ans > time_) ans = time_;
}

void comb(int k, int s) {
    if (k == M) {
        spread();
    } else {
        for (int i = s; i <= virus_size + (k - M); ++i) {
            selected[k] = i;
            comb(k + 1, i + 1);
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            scanf("%d", &lab[i][j]);
            if (lab[i][j] == 0) ++blank;
            else if (lab[i][j] == 2) virus.push_back({i, j});
        }
    virus_size = virus.size();
    if (!blank) {
        printf("0");
    } else {
        selected = vector<int>(M);
        comb(0, 0);
        printf("%d", ans == 2e9 ? -1 : ans);
    }
    return 0;
}
