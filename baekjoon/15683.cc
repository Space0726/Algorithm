#include <iostream>
#include <vector>

using namespace std;

int N, M, p[8], ans = 65;
vector<vector<int>> m;
vector<pair<int, int>> cctvs;
vector<vector<vector<int>>> dx(6), dy(6);

void update_ans(vector<vector<int>> v) {
    int cnt = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (!v[i][j])
                ++cnt;
    ans = ans > cnt ? cnt : ans;
}

vector<vector<int>> set_cctv() {
    int xx, yy, x, y, tv_type;
    vector<vector<int>> ret = m;
    for (int i = 0; i < cctvs.size(); ++i) {
        tv_type = m[cctvs[i].first][cctvs[i].second];
        for (int k = 1; k <= dx[tv_type][p[i]][0]; ++k) {
            x = cctvs[i].first, y = cctvs[i].second;
            while (1) {
                xx = x + dx[tv_type][p[i]][k], yy = y + dy[tv_type][p[i]][k];
                if (xx < 0 || xx >= N || yy < 0 || yy >= M || ret[xx][yy] == 6)
                    break;
                ret[xx][yy] = 7;
                x = xx, y = yy;
            }
        }
    }
    return ret;
}

void perm(int k) {
    if (k == cctvs.size()) {
        update_ans(set_cctv());
    } else {
        for (int i = 0; i < 4; ++i) {
            p[k] = i;
            perm(k + 1);
        }
    }
}

void init() {
    dx[1] = {{1, -1}, {1, 0}, {1, 1}, {1, 0}};
    dy[1] = {{1, 0}, {1, 1}, {1, 0}, {1, -1}};
    dx[2] = {{2, 0, 0}, {2, 1, -1}, {2, 0, 0}, {2, 1, -1}};
    dy[2] = {{2, 1, -1}, {2, 0, 0}, {2, 1, -1}, {2, 0, 0}};
    dx[3] = {{2, -1, 0}, {2, 0, 1}, {2, 1, 0}, {2, 0, -1}};
    dy[3] = {{2, 0, 1}, {2, 1, 0}, {2, 0, -1}, {2, -1, 0}};
    dx[4] = {{3, 0, -1, 0}, {3, -1, 0, 1}, {3, 0, 1, 0}, {3, 1, 0, -1}};
    dy[4] = {{3, -1, 0, 1}, {3, 0, 1, 0}, {3, 1, 0, -1}, {3, 0, -1, 0}};
    dx[5] = {{4, -1, 0, 1, 0}, {4, -1, 0, 1, 0}, {4, -1, 0, 1, 0}, {4, -1, 0, 1, 0}};
    dy[5] = {{4, 0, 1, 0, -1}, {4, 0, 1, 0, -1}, {4, 0, 1, 0, -1}, {4, 0, 1, 0, -1}};
}

int main() {
    scanf("%d%d", &N, &M);
    m = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            scanf("%d", &m[i][j]);
            if (m[i][j] && m[i][j] < 6)
                cctvs.push_back({i, j});
        }
    init();
    perm(0);
    printf("%d", ans);
    return 0;
}
