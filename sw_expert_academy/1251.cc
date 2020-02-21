#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from;
    int to;
    long long weight;
    Edge(int f, int t, long long w): from(f), to(t), weight(w){}
};

struct LandSet {
    int num;
    pair<long long, long long> loc;
    LandSet *parent = NULL;
    int find_root() {
        if (parent == NULL)
            return num;
        return parent->find_root();
    }
};

int n;
double e;
vector<LandSet> lands;
vector<Edge> edges;

long long distance(pair<long long, long long> &a, pair<long long, long long> &b) {
    return (a.first - b.first)*(a.first - b.first)
           + (a.second - b.second)*(a.second - b.second);
}

long long kruskal() {
    long long min_dist = 0;
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){ return a.weight < b.weight; });
    int cnt = 0, from_root, to_root;
    for (int i = 0; i < edges.size(); ++i) {
        from_root = lands[edges[i].from].find_root();
        to_root = lands[edges[i].to].find_root();
        if (from_root != to_root) {
            min_dist += edges[i].weight;
            lands[to_root].parent = &lands[from_root];
            if (++cnt == n - 1)
                break;
        }
    }
    return min_dist;
}

void init() {
    scanf("%d", &n);
    lands = vector<LandSet>(n);
    edges = vector<Edge>();
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &lands[i].loc.first);
        lands[i].num = i;
    }
    for (int i = 0; i < n; ++i)
        scanf("%lld", &lands[i].loc.second);
    scanf("%lf", &e);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            edges.push_back(Edge(i, j, distance(lands[i].loc, lands[j].loc)));
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        init();
        printf("#%d %.lf\n", test_case, e * kruskal());
    }
    return 0;
}
