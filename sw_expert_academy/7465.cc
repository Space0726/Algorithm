#include <iostream>

using namespace std;

int n, m, set, map[100][100];

void dfs() {
    int stack[100] = {0,}, t, cur;
    bool visited[100] = {false,};
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++set;
            t = -1;
            stack[++t] = i;
            visited[i] = true;
            while (t != -1) {
                cur = stack[t--];
                for (int j = 1; j <= map[cur][0]; ++j) {
                    if (!visited[map[cur][j]]) {
                        visited[map[cur][j]] = true;
                        stack[++t] = map[cur][j];
                    }
                }
            }
        }
    }
}

int main() {
    int t, tmp1, tmp2;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        set = 0;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            map[i][0] = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &tmp1, &tmp2);
            map[tmp1-1][++map[tmp1-1][0]] = tmp2 - 1;
            map[tmp2-1][++map[tmp2-1][0]] = tmp1 - 1;
        }
        dfs();
        printf("#%d %d\n", test_case, set);
    }
    return 0;
}
