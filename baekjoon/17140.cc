#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, K, arr[101][101], ans;
struct Num {
    int n, cnt;
    bool operator<(const Num& other) const {
        if (this->cnt == other.cnt)
            return this->n < other.n;
        return this->cnt < other.cnt;
    }
};

int r_op(int r) {
    int max_c = 0;
    for (int i = 1; i <= r; ++i) {
        unordered_map<int, int> m;
        vector<Num> tmp;
        for (int j = 1; j <= arr[i][0]; ++j) {
            if (arr[i][j] == 0) continue;
            if (m.find(arr[i][j]) == m.end())
                m[arr[i][j]] = 1;
            else
                ++m[arr[i][j]];
        }
        for (const auto& ii: m)
            tmp.push_back({ii.first, ii.second});
        sort(tmp.begin(), tmp.end());
        int size = tmp.size();
        if (size > 50) size = 50;
        for (int j = 0; j < size; ++j) {
            arr[i][(j << 1) + 1] = tmp[j].n;
            arr[i][(j << 1) + 2] = tmp[j].cnt;
        }
        if (arr[i][0] > size << 1)
            for (int j = (size << 1) + 1; j <= arr[i][0]; ++j)
                arr[i][j] = 0;
        arr[i][0] = size << 1;
        max_c = max_c < arr[i][0] ? arr[i][0] : max_c;
    }
    for (int i = 1; i <= max_c; ++i)
        arr[0][i] = r;
    return max_c;
}

int c_op(int c) {
    int max_r = 0;
    for (int i = 1; i <= c; ++i) {
        unordered_map<int, int> m;
        vector<Num> tmp;
        for (int j = 1; j <= arr[0][i]; ++j) {
            if (arr[j][i] == 0) continue;
            if (m.find(arr[j][i]) == m.end())
                m[arr[j][i]] = 1;
            else
                ++m[arr[j][i]];
        }
        for (const auto& ii: m)
            tmp.push_back({ii.first, ii.second});
        sort(tmp.begin(), tmp.end());
        int size = tmp.size();
        if (size > 50) size = 50;
        for (int j = 0; j < size; ++j) {
            arr[(j << 1) + 1][i] = tmp[j].n;
            arr[(j << 1) + 2][i] = tmp[j].cnt;
        }
        if (arr[0][i] > size << 1)
            for (int j = (size << 1) + 1; j <= arr[0][i]; ++j)
                arr[j][i] = 0;
        arr[0][i] = size << 1;
        max_r = max_r < arr[0][i] ? arr[0][i] : max_r;
    }
    for (int i = 1; i <= max_r; ++i)
        arr[i][0] = c;
    return max_r;
}

void op() {
    if (arr[R][C] == K) return;
    int r = 3, c = 3;
    for (int i = 1; i <= 100; ++i) {
        if (r < c) r = c_op(c);
        else c = r_op(r);
        if (arr[R][C] == K) {
            ans = i;
            return;
        }
    }
    ans = -1;
}

int main() {
    scanf("%d%d%d", &R, &C, &K);
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            scanf("%d", &arr[i][j]);
    arr[1][0] = arr[2][0] = arr[3][0] = 3;
    arr[0][1] = arr[0][2] = arr[0][3] = 3;
    op();
    printf("%d", ans);
    return 0;
}
