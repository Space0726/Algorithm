#include <iostream>

using namespace std;

int n, m, set, p[100], rank_[100];

void init() {
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        rank_[i] = 0;
    }
}

int find_set(int a) {
    if (p[a] != a) p[a] = find_set(p[a]);
    return p[a];
}

void link(int a, int b) {
    if (rank_[a] > rank_[b]) {
        p[b] = a;
    } else {
        p[a] = b;
        if (rank_[a] == rank_[b])
            ++rank_[b];
    }
}

bool union_set(int a, int b) {
    int pa = find_set(a), pb = find_set(b);
    if (pa == pb) return false;
    link(pa, pb);
    return true;
}

int main() {
    int t, tmp1, tmp2;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        scanf("%d%d", &n, &m);
        set = n;
        init();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &tmp1, &tmp2);
            if (union_set(--tmp1, --tmp2))
                --set;
        }
        printf("#%d %d\n", test_case, set);
    }
    return 0;
}
