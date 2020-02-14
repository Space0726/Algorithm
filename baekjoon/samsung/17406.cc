#include <iostream>
#include <vector>

using namespace std;

struct Rotate {
    int r;
    int c;
    int s;
    Rotate(int r_, int c_, int s_) {
        this->r = r_;
        this->c = c_;
        this->s = s_;
    }
};

int n, m, k, min_sum = 1e4;
vector<vector<int>> origin_v, v;
vector<Rotate> rotates;
vector<bool> check;
vector<int> perm;

void rot() {
    int tmp, rot_cnt, diff_first, diff_second, x, y;
    pair<int, int> start, end;
    for (int idx = 0; idx < k; ++idx) {
        Rotate rots = rotates[perm[idx] - 1];
        start = { rots.r - rots.s - 1, rots.c - rots.s - 1 };
        end = { rots.r + rots.s - 1, rots.c + rots.s - 1 };
        diff_first = end.first - start.first;
        diff_second = end.second - start.second;
        rot_cnt = (diff_first > diff_second ? diff_second : diff_first) / 2;
        for (int cnt = 0; cnt < rot_cnt; ++cnt) {
            x = start.first + cnt; y = start.second + cnt;
            tmp = v[x][y];
            for (int i = x + 1; i <= end.first - cnt; ++i)
                v[i - 1][y] = v[i][y];
            for (int j = y + 1; j <= end.second - cnt; ++j)
                v[end.first - cnt][j - 1] = v[end.first - cnt][j];
            for (int i = end.first - cnt - 1; i >= x; --i)
                v[i + 1][end.second - cnt] = v[i][end.second - cnt];
            for (int j = end.second - cnt - 1; j >= y + 1; --j)
                v[x][j + 1] = v[x][j];
            v[x][y + 1] = tmp;
        }
    }
}

int get_min_sum() {
    int sum;
    for (int i = 0; i < n; ++i) {
        sum = 0;
        for (int j = 0; j < m; ++j)
            sum += v[i][j];
        if (min_sum > sum)
            min_sum = sum;
    }
    return min_sum;
}

void permutation(int num) {
    if (num == k) {
        v = origin_v;
        rot();
        get_min_sum();
    }
    else {
        for (int i = 0; i < k; ++i) {
            if (!check[i]) {
                check[i] = true;
                perm[i] = num + 1;
                permutation(num + 1);
                check[i] = false;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    origin_v = vector<vector<int>>(n, vector<int>(m));
    check = vector<bool>(k);
    perm = vector<int>(k);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &origin_v[i][j]);
    int r_, c_, s_;
    for (int i = 0; i < k; ++i) {
        scanf("%d %d %d", &r_, &c_, &s_);
        rotates.push_back(Rotate(r_, c_, s_));
    }
    permutation(0);
    printf("%d\n", min_sum);
    return 0;
}
