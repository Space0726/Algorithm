#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, population[10], adj[10][10], t[10], ans = 2e9, r;

void update_ans() {
    int a_sum = 0, b_sum = 0;
    for (int i = 0; i < N; ++i) {
        if (t[i]) a_sum += population[i];
        else b_sum += population[i];
    }
    int diff = abs(a_sum - b_sum);
    if (ans > diff) ans = diff;
}

bool is_valid() {
    int sum = 2, start;
    vector<bool> visited(N);
    queue<int> q;
    for (int i = 0; i < N; ++i)
        if (t[i]) { start = i; break; }
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        start = q.front(); q.pop();
        for (int i = 1; i <= adj[start][0]; ++i) {
            if (!visited[adj[start][i]] && t[adj[start][i]]) {
                visited[adj[start][i]] = true;
                q.push(adj[start][i]);
                ++sum;
            }
        }
    }
    for (int i = 0; i < N; ++i)
        if (!t[i]) { start = i; break; }
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        start = q.front(); q.pop();
        for (int i = 1; i <= adj[start][0]; ++i) {
            if (!visited[adj[start][i]] && !t[adj[start][i]]) {
                visited[adj[start][i]] = true;
                q.push(adj[start][i]);
                ++sum;
            }
        }
    }
    return sum == N;
}

void comb(int k, int s) {
    if (k == r) {
        if (is_valid()) update_ans();
    } else {
        for (int i = s; i <= N + (k - r); ++i) {
            t[i] = 1;
            comb(k + 1, i + 1);
            t[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", population + i);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &adj[i][0]);
        for (int j = 1; j <= adj[i][0]; ++j) {
            scanf("%d", &adj[i][j]);
            --adj[i][j];
        }
    }
    for (int i = 1; i < N; ++i) {
        r = i;
        comb(0, 0);
    }
    printf("%d", ans == 2e9 ? -1 : ans);
    return 0;
}
