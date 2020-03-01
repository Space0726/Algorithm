#include <iostream>

using namespace std;

int n, m, ans, graph[10][10];
bool visited[10];

void dfs(int node, int k) {
    if (ans == n) return;
    ans = ans < k ? k : ans;
    for (int i = 1; i <= graph[node][0]; ++i) {
        if (visited[graph[node][i]])
            continue;
        visited[graph[node][i]] = true;
        dfs(graph[node][i], k + 1);
        visited[graph[node][i]] = false;
    }
}

bool is_dup(int from, int to) {
    for (int i = 1; i <= graph[from][0]; ++i)
        if (graph[from][i] == to)
            return true;
    return false;
}

int main() {
    int T, from, to;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            graph[i][0] = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &from, &to);
            if (is_dup(from - 1, to - 1))
                continue;
            graph[from - 1][++graph[from - 1][0]] = to - 1;
            graph[to - 1][++graph[to - 1][0]] = from - 1;
        }
        ans = 0;
        for (int i = 0; i < n; ++i) {
            visited[i] = true;
            dfs(i, 1);
            visited[i] = false;
        }
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
