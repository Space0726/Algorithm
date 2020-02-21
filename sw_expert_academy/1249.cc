#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int>> map;
vector<vector<int>> min_steps;

void dfs() {
    int x, y, xx, yy, cur_step;
    bool is_push;
    stack<pair<int, int>> st;
    st.push({0, 0});
    min_steps[0][0] = 0;
    while(!st.empty()) {
        x = st.top().first;
        y = st.top().second;
        cur_step = min_steps[x][y];
        is_push = false;
        for (int i = 0; i < 4; ++i) {
            xx = x + dx[i];
            yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= n)
                continue;
            if (min_steps[xx][yy] <= cur_step + map[xx][yy] || min_steps[n-1][n-1] <= cur_step + map[xx][yy])
                continue;
            min_steps[xx][yy] = cur_step + map[xx][yy];
            if (xx == n-1 && yy == n-1)
                continue;
            st.push({xx, yy});
            is_push = true;
        }
        if (!is_push)
            st.pop();
    }
}

int main() {
    freopen("input_1249.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        int tmp = 0;
        char ch;
        scanf("%d", &n);
        map = vector<vector<int>>(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf(" %c", &ch);
                map[i][j] = ch - '0';
                tmp += map[i][j];
            }
        }
        min_steps = vector<vector<int>>(n, vector<int>(n, tmp));
        dfs();
        printf("#%d %d\n", test_case, min_steps[n-1][n-1]);
    }
    return 0;
}
