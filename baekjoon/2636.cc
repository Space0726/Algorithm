#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int r, c;
int board[100][100] = { 0, };
set<pair<int, int>> p;

void let_melt() {
    for (auto &a : p)
        board[a.first][a.second] = 0;
    p.clear();
}

void melt_dfs() {
    vector<pair<int, int>> stack;
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    int x, y, xx, yy;
    int t = -1;
    stack.push_back(make_pair(0, 0));
    ++t;
    while (t != -1) {
        x = stack[t].first;
        y = stack[t--].second;
        stack.pop_back();
        if (!visited[x][y]) {
            visited[x][y] = true;
            for (int i = 0; i < 4; i++) {
                xx = x + dx[i];
                yy = y + dy[i];
                if (xx < 0 || xx >= r || yy < 0 || yy >= c)
                    continue;
                if (board[xx][yy])
                    p.insert(make_pair(xx, yy));
                else if (!visited[xx][yy]) {
                    stack.push_back(make_pair(xx, yy));
                    ++t;
                }
            }
        }
    }
}

int main() {
    int i, j, melted, cnt = 0, time = 0;
    scanf("%d %d", &r, &c);
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf(" %d", &board[i][j]);
            if (board[i][j])
                ++cnt;
        }
    }
    while (cnt > 0) {
        melt_dfs();
        melted = p.size();
        let_melt();
        cnt -= melted;
        ++time;
    }
    printf("%d\n%d\n", time, melted);

    return 0;
}
