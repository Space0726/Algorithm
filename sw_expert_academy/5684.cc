#include <iostream>

using namespace std;

int N, M, min_, graph[401][401], shortest[401][401];
bool visited[401], check[401];

void floyd() {
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (shortest[i][j] > shortest[i][k] + shortest[k][j])
                    shortest[i][j] = shortest[i][k] + shortest[k][j];
}

bool dfs(int u) {
    visited[u] = true;
    check[u] = true;
    for (int i = 0; i < N; ++i) {
        if (graph[u][i]) {
            if (!visited[i] && dfs(graph[u][i]))
                return true;
            else if (check[i])
                return true;
        }
    }
    visited[u] = false;
    return false;
}

int main() {
    int T, t1, t2, t3;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; ++i) {
            visited[i] = check[i] = false;
            for (int j = 0; j < N; ++j) {
                graph[i][j] = 0;
                shortest[i][j] = 10001;
            }
        }
        for (int i = 0; i < M; ++i) {
            scanf("%d%d%d", &t1, &t2, &t3);
            graph[t1][t2] = t3;
            shortest[t1][t2] = t3;
        }
        floyd();
        printf("#%d %d\n", test_case, min_);
    }
    return 0;
}
