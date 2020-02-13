#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Shark {
    int r;
    int c;
    int size = 2;
    int eat_cnt = 0;
    void eat_fish() {
        if (++eat_cnt == size) {
            ++size;
            eat_cnt = 0;
        }
    }
};

int n, time = 0;
vector<vector<int>> v;
Shark baby;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

pair<int, int> bfs() {
    int cnt = 0, x, y, xx, yy;
    bool find_fish = false;
    vector<vector<bool>> visited(n, vector<bool>(n));
    pair<int, int> locate = { -1, -1 };
    queue<pair<int, int>> q;
    q.push(make_pair(baby.r, baby.c));
    visited[baby.r][baby.c] = true;
    while (!find_fish && !q.empty()) {
        ++cnt;
        int q_size = q.size();
        for (int i = 0; i < q_size; ++i) {
            x = q.front().first;
            y = q.front().second;
            for (int k = 0; k < 4; ++k) {
                xx = x + dx[k];
                yy = y + dy[k];
                if (xx < 0 || xx >= n || yy < 0 || yy >= n || visited[xx][yy] || v[xx][yy] > baby.size)
                    continue;
                if (0 < v[xx][yy] && v[xx][yy] < baby.size) {
                    if (!find_fish) {
                        locate.first = xx;
                        locate.second = yy;
                        find_fish = true;
                    }
                    else {
                        if (locate.first > xx) {
                            locate.first = xx;
                            locate.second = yy;
                        }
                        else if (locate.first == xx && locate.second > yy) {
                            locate.first = xx;
                            locate.second = yy;
                        }
                    }
                }
                visited[xx][yy] = true;
                q.push(make_pair(xx, yy));
            }
            q.pop();
        }
    }
    if (find_fish)
        time += cnt;
    return locate;
}

int main() {
    scanf("%d", &n);
    v = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &v[i][j]);
            if (v[i][j] == 9) {
                baby.r = i;
                baby.c = j;
                v[i][j] = 0;
            }
        }
    }
    pair<int, int> locate;
    while (1) {
        locate = bfs();
        if (locate.first == -1)
            break;
        v[locate.first][locate.second] = 0;
        baby.r = locate.first;
        baby.c = locate.second;
        baby.eat_fish();
    }
    printf("%d\n", time);
    return 0;
}
