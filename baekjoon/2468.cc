#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n;
vector<vector<int>> mat;
vector<vector<int>> cp_mat;

void dfs(int x, int y, int depth) {
    cp_mat[x][y] = 0;
    int xx, yy;
    for (int i = 0; i < 4; i++) {
        xx = x + dx[i];
        yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= n)
            continue;
        if (cp_mat[xx][yy] > depth)
            dfs(xx, yy, depth);
    }
}

int main() {
    int min_depth = 101, max_depth = 0;
    cin >> n;
    mat = vector<vector<int>>(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            if (mat[i][j] > max_depth)
                max_depth = mat[i][j];
            if (mat[i][j] < min_depth)
                min_depth = mat[i][j];
        }
    }

    int max_safe = 0, t;
    if (min_depth == max_depth)
        max_safe = 1;
    for (int i = min_depth; i < max_depth; i++) {
        t = 0;
        cp_mat = mat;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (cp_mat[j][k] > i) {
                    ++t;
                    dfs(j, k, i);
                }
            }
        }
        if (t > max_safe)
            max_safe = t;
    }
    
    cout << max_safe << '\n';
    return 0;
}
