#include <iostream>
#include <vector>

using namespace std;

int N, M, map[50][50], comb_save[13], c_cnt, ans = 2e9;
vector<pair<int, int>> chickens, homes;

inline int dist(pair<int, int> &from, pair<int, int> &to) {
    return abs(from.first - to.first) + abs(from.second - to.second);
}

void calc_dist() {
    int sum = 0;
    for (pair<int, int> &h: homes) {
        int min_dist = 2e9, t;
        for (int i = 0; i < M; ++i) {
            t = dist(h, chickens[comb_save[i]]);
            if (min_dist > t)
                min_dist = t;
        }
        sum += min_dist;
    }
    ans = ans > sum ? sum : ans;
}

void comb(int k, int s) {
    if (k == M) {
        calc_dist();
    } else {
        for (int i = s; i <= c_cnt + (k - M); ++i) {
            comb_save[k] = i;
            comb(k + 1, i + 1);
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2)
                chickens.push_back({i, j});
            else if (map[i][j] == 1)
                homes.push_back({i, j});
        }
    c_cnt = chickens.size();
    comb(0, 0);
    printf("%d\n", ans);
    return 0;
}
