#include <iostream>

using namespace std;

struct Edge {
    int to;
    long long weight;
    Edge() {}
    Edge(int a, long long b): to(a), weight(b) {}
    bool operator<(const Edge &other) const {
        return this->weight < other.weight;
    }
    bool operator>(const Edge &other) const {
        return this->weight > other.weight;
    }
    bool operator>=(const Edge &other) const {
        return this->weight >= other.weight;
    }
};

class PQ {
public:
    Edge pq[499501];
    int e;

    bool is_empty() { return !e; }

    void push(Edge edge) {
        int p = ++e;
        while (p > 1 && pq[p >> 1] > edge) {
            pq[p] = pq[p >> 1];
            p >>= 1;
        }
        pq[p] = edge;
    }

    Edge pop() {
        int cur = 1, child = 2;
        Edge ret = pq[cur];
        e--;
        while (child <= e) {
            if (child + 1 <= e && pq[child] > pq[child + 1])
                ++child;
            if (pq[child] >= pq[e + 1])
                break;
            pq[cur] = pq[child];
            cur = child;
            child <<= 1;
        }
        pq[cur] = pq[e + 1];
        return ret;
    }
};

int N, land[1000][2];
bool visited[1000];
long long ans, dist[1000], length[1000][1000];
double E;
PQ pq_;

inline long long distance(int ax, int ay, int bx, int by) {
    return (long long)(bx - ax)*(bx - ax) + (long long)(by - ay)*(by - ay);
}

void calc_distance() {
    int cnt = 0;
    for (int i = 0; i < N - 1; ++i)
        for (int j = i + 1; j < N; ++j)
            length[i][j] = length[j][i] = distance(land[i][0], land[i][1], land[j][0], land[j][1]);
}

void prim() {
    ans = 0;
    Edge tmp;
    pq_.push(Edge(0, 0));
    while (!pq_.is_empty()) {
        tmp = pq_.pop();
        if (tmp.weight < dist[tmp.to]) {
            ans += tmp.weight;
            visited[tmp.to] = true;
            dist[tmp.to] = tmp.weight;
            for (int i = 0; i < N; ++i)
                if (!visited[i])
                    pq_.push(Edge(i, length[tmp.to][i]));
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &land[i][0]);
            visited[i] = false;
            dist[i] = 2e12 + 1;
        }
        for (int i = 0; i < N; ++i)
            scanf("%d", &land[i][1]);
        scanf("%lf", &E);
        calc_distance();
        prim();
        printf("#%d %.lf\n", test_case, ans * E);
    }
    return 0;
}
