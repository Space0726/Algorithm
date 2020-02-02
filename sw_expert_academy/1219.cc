#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> edges;

bool dfs(int node) {
    if (edges[0][node] == 99 || edges[1][node] == 99)
        return true;
    printf("%d %d %d\n", node, edges[0][node], edges[1][node]);
    if (edges[0][node] != -1)
        if (dfs(node+1))
            return true;
    if (edges[1][node] != -1)
        if (dfs(node+1))
            return true;
    return false;
}

int main() {
    freopen("input_1219.txt", "r", stdin);
    for (int T = 1; T <= 10; T++) {
        int test_case, num, i, j, x, y;
        scanf("%d %d", &test_case, &num);
        edges = vector<vector<int>>(2, vector<int>(100, -1));
        for (i = 0; i < num; i++) {
            scanf(" %d %d", &x, &y);
            if (edges[0][x] == -1)
                edges[0][x] = y;
            else
                edges[1][x] = y;
        }
        printf("#%d %d\n", test_case, dfs(0));
    }

    return 0;
}
