#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct SegmentTree {
    int arr[2000002], bias;

    void init(int n) {
        memset(arr, 0, sizeof(arr));
        for (bias = 1; bias < n; bias <<= 1);
    }
    void update(int x, int v) {
        x |= bias;
        arr[x] = v;
        while (x >>= 1) {
            arr[x] = arr[x << 1] + arr[x << 1 | 1];
        }
    }
    int query(int l, int r) {
        l |= bias, r |= bias;
        int lval = 0, rval = 0;
        while (l <= r) {
            if (l & 1) lval = lval + arr[l++];
            if (!(r & 1)) rval = rval + arr[r--];
            l >>= 1, r >>= 1;
        }
        return lval + rval;
    }
};

int ans[500001], N;
vector<pair<int, int>> v;
SegmentTree tree;

int main() {
    scanf("%d", &N);
    v = vector<pair<int, int>>(N);
    tree.init(N);
    int t;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &t);
        v[i] = {i + 1, t};
    }
    sort(v.begin(), v.end(),
         [](pair<int, int> &a, pair<int, int> &b) { return a.second < b.second; });
    for (pair<int, int> &i: v) {
        int idx = i.first;
        ans[idx] = idx - tree.query(1, idx - 1);
        tree.update(idx, 1);
    }
    for (int i = 1; i <= N; ++i)
        printf("%d\n", ans[i]);
}
