#include <iostream>
#include <vector>

using namespace std;

int N, M, ans;
vector<vector<int>> adj, memo;

int max(int a, int b) { return a < b ? b : a; }

int dfs(int v, int visited) {
    if (memo[visited][v]) return memo[visited][v];
    int ret = 1;
    for (int i = 1; i <= N; ++i)
        if (adj[v][i] == 1 && !(visited & (1 << i)))
            ret = max(ret, dfs(i, visited | (1 << i)) + 1);
    return memo[visited][v] = ret;
}

int main() {
    int T, a, b;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d%d", &N, &M);
        adj = vector<vector<int>>(N + 1, vector<int>(N + 1));
        memo = vector<vector<int>>(1 << (N + 1), vector<int>(N + 1));
        for (int i = 0; i < M; ++i) {
            scanf("%d%d", &a, &b);
            adj[a][b] = adj[b][a] = 1;
        }
        ans = 1;
        for (int i = 1; i <= N; ++i)
            ans = max(ans, dfs(i, 1 << i));
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
