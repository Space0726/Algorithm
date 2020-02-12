#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int min_time = 1e9;
int zeros = 0;
vector<vector<int>> lab;
vector<pair<int, int>> virus;
vector<int> arr, t;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
    vector<vector<int>> cp_lab = lab;
    vector<vector<bool>> visited(n, vector<bool>(n));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
        cp_lab[virus[t[i]].first][virus[t[i]].second] = 3;
        visited[virus[t[i]].first][virus[t[i]].second] = true;
        q.push(make_pair(virus[t[i]].first, virus[t[i]].second));
    }
    int x, y, xx, yy, t = 1, cur_zeros = zeros;
    while (1) {
        int cur_size = q.size();
        int not_zeros = 0;
        for (int i = 0; i < cur_size; ++i) {
            x = q.front().first;
            y = q.front().second;
            for (int k = 0; k < 4; ++k) {
                xx = x + dx[k];
                yy = y + dy[k];
                if (xx < 0 || xx >= n || yy < 0 || yy >= n || cp_lab[xx][yy] == 1 || visited[xx][yy])
                    continue;
                if (!cp_lab[xx][yy])
                    ++not_zeros;
                cp_lab[xx][yy] = 3;
                visited[xx][yy] = true;
                q.push(make_pair(xx, yy));
            }
            q.pop();
        }
        if (!not_zeros && cur_zeros)
            return;
        cur_zeros -= not_zeros;
        if (!cur_zeros) {
            if (min_time > t)
                min_time = t;
            return;
        }
        not_zeros = 0;
        ++t;
    }
}

void comb(int n, int r) {
    if (r == 0) {
        bfs();
    } else if (n < r) {
        return;
    } else {
        t[r-1] = arr[n-1];
        comb(n-1, r-1);
        comb(n-1, r);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    lab = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d ", &lab[i][j]);
            if (!lab[i][j])
                ++zeros;
            if (lab[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }
    if (!zeros) {
        printf("0\n");
        return 0;
    }

    int virus_num = virus.size();
    for (int i = 0; i < virus_num; ++i)
        arr.push_back(i);
    t = vector<int>(m);
    comb(virus_num, m);
    min_time = min_time == 1e9 ? -1 : min_time;
    printf("%d\n", min_time);

    return 0;
}
