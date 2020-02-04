#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> edges;
vector<vector<bool>> visited;

bool dfs(int x, int y) {
    visited[x][y] = true;
    if (edges[x][y] == 99)
        return true;
    for (int i = 0; i < 2; ++i)
        if (edges[x][y] != -1 && !visited[i][edges[x][y]] && dfs(i, edges[x][y]))
            return true;
    return false;
}

int main() {
    for (int T = 1; T <= 10; ++T) {
        int test_case, edge_len, i, x, y;
        edges = vector<vector<int>>(2, vector<int>(100, -1));
        visited = vector<vector<bool>>(2, vector<bool>(100, false));
        scanf("%d %d", &test_case, &edge_len);
        for (i = 0; i < edge_len; ++i) {
            scanf(" %d %d", &x, &y);
            if (edges[0][x] == -1)
                edges[0][x] = y;
            else
                edges[1][x] = y;
        }
        printf("#%d %d\n", test_case, dfs(0, 0));
    }
    return 0;
} 
