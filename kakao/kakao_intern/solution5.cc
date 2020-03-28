#include <vector>
#include <algorithm>

using namespace std;

int base, seg_tree[800000];

void make_seg_tree(vector<int>& s) {
    for (base = 1; base < s.size(); base <<= 1);
    for (int i = base; i < s.size() + base; ++i)
        seg_tree[i] = s[i-base];
    for (int i = base - 1; i > 0; --i)
        seg_tree[i] = max(seg_tree[i << 1], seg_tree[(i << 1) + 1]);
}

int range_max(int a, int b) {
    int max_val = 0;
    while (a < b) {
        if (a & 1) max_val = max(max_val, seg_tree[a++]);
        if (!(b & 1)) max_val = max(max_val, seg_tree[b--]);
        a >>= 1, b >>= 1;
    }
    if (a == b) max_val = max(max_val, seg_tree[a]);
    return max_val;
}

int solution(vector<int> stones, int k) {
    int answer = 2e9 + 1;
    make_seg_tree(stones);
    for (int i = 0; i + k <= stones.size(); ++i) {
        int max_val = range_max(base + i, base + i + k - 1);
        answer = min(answer, max_val);
    }
    return answer;
}
