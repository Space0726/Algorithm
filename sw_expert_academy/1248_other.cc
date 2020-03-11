#include <iostream>

using namespace std;

int V, E, from, to, ans, child, tree[10001][3], stack[10001], t;
bool visited[10001];

void dfs() {
    int cur, cnt = 0;
    t = -1;
    visited[ans] = true;
    stack[++t] = ans;
    while (t != -1) {
        cur = stack[t--];
        ++cnt;
        for (int i = 0; i < 2; ++i) {
            if (tree[cur][i] > 0 && !visited[tree[cur][i]]) {
                stack[++t] = tree[cur][i];
                visited[stack[t]] = true;
            }
        }
    }
    child = cnt;
}

void lca() {
    int parent = from, tmp;
    while (parent > 0) {
        tmp = tree[parent][2];
        tree[parent][2] = -1;
        parent = tmp;
    }
    parent = to;
    while (tree[parent][2] != -1)
        parent = tree[parent][2];
    ans = parent;
}

int main() {
    int T, t1, t2;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d%d%d%d", &V, &E, &from, &to);
        for (int i = 1; i <= V; ++i)
            tree[i][0] = tree[i][1] = tree[i][2] = visited[i] = 0;
        for (int i = 0; i < E; ++i) {
            scanf("%d%d", &t1, &t2);
            if (tree[t1][0])
                tree[t1][1] = t2;
            else
                tree[t1][0] = t2;
            tree[t2][2] = t1;
        }
        lca();
        dfs();
        printf("#%d %d %d\n", test_case, ans, child);
    }
    return 0;
}
