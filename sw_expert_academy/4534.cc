#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> adj;
vector<vector<long long>> memo;

long long dfs(int v, int color, int parent) {
    if (memo[color][v])
        return memo[color][v];
    long long ret = 1;

    // color = 0 is black, 1 is white
    if (color == 0) {
        for (int i = 0; i < adj[v].size(); ++i) {
            if (adj[v][i] != parent) {
                ret *= dfs(adj[v][i], 1, v);
                ret %= 1000000007;
            }
        }
    }
    else {
        for (int i = 0; i < adj[v].size(); ++i) {
            if (adj[v][i] != parent) {
                ret *= dfs(adj[v][i], 1, v) + dfs(adj[v][i], 0, v);
                ret %= 1000000007;
            }
        }
    }
    memo[color][v] = ret;
    return ret;
}

int main() {
    int T, from, to;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d", &n);
        adj = vector<vector<int>>(n + 1, vector<int>());
        memo = vector<vector<long long>>(2, vector<long long>(n + 1));
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d", &from, &to);
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        printf("#%d %lld\n", test_case, (dfs(1, 0, -1) + dfs(1, 1, -1)) % 1000000007);
    }
}
