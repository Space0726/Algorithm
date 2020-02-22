#include <cstdio>
#include <vector>

using namespace std;
int n, m;
vector<vector<int>> arr;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int melt() {
    vector<vector<int>> melting_area(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    int x, y, xx, yy, t;
    int melt_cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && arr[i][j]) {
                x = i; y = j;
                t = -1;
                vector<pair<int, int>> stack;
                stack.push_back(make_pair(x, y));
                ++t;
                while (t != -1) {
                    x = stack[t].first;
                    y = stack[t].second;
                    stack.pop_back();
                    --t;
                    if (visited[x][y])
                        continue;
                    visited[x][y] = true;
                    for (int k = 0; k < 4; ++k) {
                        xx = x + dx[k]; yy = y + dy[k];
                        if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                            continue;
                        if (!arr[xx][yy])
                            ++melting_area[x][y];
                        else if (!visited[xx][yy]) {
                            stack.push_back(make_pair(xx, yy));
                            ++t;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (melting_area[i][j]) {
                arr[i][j] = arr[i][j] < melting_area[i][j] ? 0 : arr[i][j] - melting_area[i][j];
                ++melt_cnt;
            }
    return melt_cnt;
}

void find_glacial(int x, int y, vector<vector<bool>> &visited) {
    int xx, yy, t;
    t = -1;
    vector<pair<int, int>> stack;
    stack.push_back(make_pair(x, y));
    ++t;
    while (t != -1) {
        x = stack[t].first;
        y = stack[t].second;
        visited[x][y] = true;
        stack.pop_back();
        --t;
        for (int k = 0; k < 4; ++k) {
            xx = x + dx[k]; yy = y + dy[k];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                continue;
            if (arr[xx][yy] && !visited[xx][yy]) {
                stack.push_back(make_pair(xx, yy));
                ++t;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    arr = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf(" %d", &arr[i][j]);
    int ans = 0, glacial_cnt = 0;
    while (melt()) {
        ++ans;
        vector<vector<bool>> visited(n, vector<bool>(m));
        glacial_cnt = 0;
        for (int i = 1; i < n-1; ++i) {
            for (int j = 1; j < m-1; ++j) {
                if (arr[i][j] && !visited[i][j]) {
                    if (glacial_cnt > 0)
                        goto end;
                    find_glacial(i, j, visited);
                    ++glacial_cnt;
                }
            }
        }
    }
end:
    ans = glacial_cnt ? ans : 0;
    printf("%d\n", ans);
    return 0;
}
