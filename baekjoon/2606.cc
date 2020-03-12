#include <iostream>

using namespace std;

int N, p[101], rank_[101], num[101];

int find_set(int a) {
    if (p[a] != a) p[a] = find_set(p[a]);
    return p[a];
}

int main() {
    int e, t1, t2, a, b;
    scanf("%d%d", &N, &e);
    for (int i = 1; i <= N; ++i) {
        p[i] = i;
        num[i] = 1;
    }
    for (int i = 0; i < e; ++i) {
        scanf("%d%d", &t1, &t2);
        a = find_set(t1), b = find_set(t2);
        if (a != b) {
            if (rank_[a] > rank_[b]) {
                p[b] = a;
                num[a] += num[b];
            } else {
                p[a] = b;
                num[b] += num[a];
                if (rank_[a] == rank_[b])
                    ++rank_[b];
            }
        }
    }
    printf("%d", num[find_set(1)] - 1);
    return 0;
}
