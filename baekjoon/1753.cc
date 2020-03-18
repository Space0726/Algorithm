#include <iostream>

#define MAX_VAL 2000000000

using namespace std;

struct Node {
    int to;
    int weight;
    Node() {}
    Node(int a, int b): to(a), weight(b) {}
    bool operator<(const Node &other) {
        return this->weight < other.weight;
    }
    bool operator>(const Node &other) {
        return this->weight > other.weight;
    }
};

int V, E, K, weight[20001][20001], dist[20001], e = 1;
bool visited[20001];
Node pq[20001];

void dijkstra() {
    push(Node{1, 0});
    visited[1] = true;
    while (e) {

    }
}

int main() {
    int u, v, w;
    scanf("%d%d%d", &V, &E, &K);
    for (int i = 1; i < V; ++i)
        dist[i] = MAX_VAL;
    for (int i = 0; i < E; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        if (!weight[u][v] || weight[u][v] > w)
            weight[u][v] = w;
    }
    dijkstra();
    printf("0\n");
    for (int i = 1; i < V; ++i) {
        if (dist[i] == MAX_VAL)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
    return 0;
}
