#include <iostream>
#include <queue>

using namespace std;

int N, M, T, plate[50][50], pos[50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void apply_avg() {
    int sum = 0, cnt = 0;
    double avg;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (plate[i][j]) { sum += plate[i][j]; ++cnt; }
    avg = (double) sum / cnt;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (plate[i][j])
                if (plate[i][j] > avg) --plate[i][j];
                else if (plate[i][j] < avg) ++plate[i][j];
}

bool del() {
    int x, y, xx, yy, rj, cur;
    bool ret = true;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            rj = (pos[i]+j) % M;
            if (plate[i][rj]) {
                queue<pair<int, int>> q;
                for (int k = 0; k < 4; ++k) {
                    xx = i + dx[k];
                    yy = pos[xx] + j + dy[k];
                    if (xx == -1 || xx == N) continue;
                    if (yy >= M) yy %= M;
                    else if (yy < 0) yy += M;
                    if (plate[xx][yy] == plate[i][rj]) {
                        cur = plate[i][rj];
                        ret = false;
                        q.push({i, j});
                        plate[i][rj] = 0;
                        break;
                    }
                }
                while (!q.empty()) {
                    x = q.front().first, y = q.front().second;
                    for (int l = 0; l < 4; ++l) {
                        xx = x + dx[l];
                        yy = pos[xx] + y + dy[l];
                        if (yy >= M) yy %= M;
                        else if (yy < 0) yy += M;
                        if (xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
                        if (plate[xx][yy] == cur) {
                            plate[xx][yy] = 0;
                            q.push({xx, y + dy[l]});
                        }
                    }
                    q.pop();
                }
            }
        }
    return ret;
}

void rot(int x, int d, int k) {
    for (int i = 1; x*i <= N; ++i)
        pos[x*i - 1] = (pos[x*i - 1] + (d ? k : (M - k))) % M;
    if (del()) apply_avg();
}

int main() {
    scanf("%d%d%d", &N, &M, &T);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &plate[i][j]);
    int x, d, k;
    for (int i = 0; i < T; ++i) {
        scanf("%d%d%d", &x, &d, &k);
        rot(x, d, k);
    }
    int sum = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            sum += plate[i][j];
    printf("%d", sum);
    return 0;
}
