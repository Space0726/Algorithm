#include <iostream>
#include <queue>

#define MAX_LEN 100
#define MAX_VAL 90001

using namespace std;

struct Node {
    pair<int, int> to;
    int weight;
    Node() {}
    Node(pair<int, int> a, int b): to(a), weight(b) {}
    bool operator<(const Node &other) const {
        return this->weight < other.weight;
    }
    bool operator>(const Node &other) const {
        return this->weight > other.weight;
    }
};

int N, dist[MAX_LEN][MAX_LEN], w[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void dijkstra() {
    int x, y, xx, yy;
    priority_queue<Node> pq;
    dist[0][0] = 0;
    pq.push(Node({0, 0}, 0));
    visited[0][0] = true;
    while (!pq.empty()) {
        x = pq.top().to.first, y = pq.top().to.second;
        pq.pop();
        if (x == N - 1 && y == N - 1)
            break;
        for (int i = 0; i < 4; i++) {
            xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= N || yy < 0 || yy >= N || visited[xx][yy])
                continue;
            if (dist[xx][yy] > dist[x][y] + w[xx][yy]) {
                visited[xx][yy] = true;
                dist[xx][yy] = dist[x][y] + w[xx][yy];
                pq.push(Node({xx, yy}, -dist[xx][yy]));
            }
        }
    }
}

int main() {
    int T;
    char tmp;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; ++j) {
                scanf(" %c", &tmp);
                w[i][j] = tmp - '0';
                dist[i][j] = MAX_VAL;
                visited[i][j] = false;
            }
        }
        dijkstra();
        printf("#%d %d\n", test_case, dist[N-1][N-1]);
    }
}
