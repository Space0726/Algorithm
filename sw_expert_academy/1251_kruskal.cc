#include <iostream>

using namespace std;

struct Edge {
    int from;
    int to;
    long long weight;
    bool operator<(const Edge &other) const {
        return this->weight < other.weight;
    }
    bool operator>=(const Edge &other) const {
        return this->weight >= other.weight;
    }
};

int N, land[1000][2];
long long ans;
Edge edges[499500];
double E;
int p[1000], rank_[1000];

namespace disjoint {
    void init() {
        for (int i = 0; i < N; ++i) {
            p[i] = i;
            rank_[i] = 0;
        }
    }

    int find_set(int a) {
        if (p[a] != a) p[a] = find_set(p[a]);
        return p[a];
    }

    bool is_same_set(int a, int b) {
        return find_set(a) == find_set(b);
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

    void union_set(int a, int b) {
        link(find_set(a), find_set(b));
    }
}

inline long long distance(int ax, int ay, int bx, int by) {
    return (long long)(bx - ax)*(bx - ax) + (long long)(by - ay)*(by - ay);
}

void calc_distance() {
    int cnt = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            edges[cnt].from = i;
            edges[cnt].to = j;
            edges[cnt++].weight = distance(land[i][0], land[i][1], land[j][0], land[j][1]);
        }
    }
}

inline void swap(int a, int b) {
    Edge t = edges[a];
    edges[a] = edges[b];
    edges[b] = t;
}

void quick_sort(int left, int right) {
    if (left >= right) return;
    swap(left, (left + right) / 2);
    int i = left, j = right + 1;
    while (i < j) {
        while (edges[left] < edges[--j]);
        while (i < j && edges[left] >= edges[++i]);
        if (i < j) swap(i, j);
    }
    swap(left, i);
    quick_sort(left, i - 1);
    quick_sort(i + 1, right);
}

void kruskal() {
    quick_sort(0, (N - 1)*N/2 - 1);
    int cnt = 0;
    ans = 0;
    disjoint::init();
    for (int i = 0; i < (N - 1)*N/2; ++i) {
        if (cnt == N - 1)
            break;
        if (!disjoint::is_same_set(edges[i].from, edges[i].to)) {
            ans += edges[i].weight;
            disjoint::union_set(edges[i].from, edges[i].to);
            ++cnt;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            scanf("%d", &land[i][0]);
        for (int i = 0; i < N; ++i)
            scanf("%d", &land[i][1]);
        scanf("%lf", &E);
        calc_distance();
        kruskal();
        printf("#%d %.lf\n", test_case, ans * E);
    }
    return 0;
}
