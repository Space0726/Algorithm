#include <iostream>

#define INF 60000001

using namespace std;

int N, M, edges[6000][3];
long long dist[500];
bool cycle;

void BellmanFord() {
    for (int i = 0; i < N-1; ++i)
        for (int j = 0; j < M; ++j)
            if (dist[edges[j][0]] != INF && dist[edges[j][1]] > dist[edges[j][0]] + edges[j][2])
                dist[edges[j][1]] = dist[edges[j][0]] + edges[j][2];
    for (int i = 0; i < M; ++i) {
        if (dist[edges[i][0]] != INF && dist[edges[i][1]] > dist[edges[i][0]] + edges[i][2]) {
            cycle = true;
            break;
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i < N; ++i)
        dist[i] = INF;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d", &edges[i][0], &edges[i][1], &edges[i][2]);
        --edges[i][0], --edges[i][1];
    }
    BellmanFord();
    if (cycle) {
        printf("-1");
    } else {
        for (int i = 1; i < N; ++i)
            printf("%lld\n", dist[i] == INF ? -1 : dist[i]);
    }
    return 0;
}
