#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, room_num, max_num;
vector<vector<int>> map;
int dx[4] = {1, -1, 0, 0,};
int dy[4] = {0, 0, 1, -1,};

void bfs() {
    int x, y, xx, yy;
    vector<vector<int>> saved(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (saved[i][j])
                continue;
            stack<pair<int, int>> st;
            int cur_num = 1;
            bool is_moved;
            pair<int, int> save = {i, j};
            x = i; y = j;
            st.push(make_pair(x, y));
            while (1) {
                is_moved = false;
                for (int k = 0; k < 4; ++k) {
                    xx = x + dx[k];
                    yy = y + dy[k];
                    if (xx < 0 || xx >= n || yy < 0 || yy >= n)
                        continue;
                    if (map[xx][yy] - map[x][y] == 1) {
                        if (saved[xx][yy]) {
                            save.first = xx;
                            save.second = yy;
                        } else {
                            x = xx; y = yy;
                            st.push(make_pair(xx, yy));
                            ++cur_num;
                            is_moved = true;
                        }
                        break;
                    }
                }
                if (!is_moved)
                    break;
            }
            for (int cnt = 1; cnt <= cur_num; ++cnt) {
                x = st.top().first;
                y = st.top().second;
                saved[x][y] = saved[save.first][save.second] + cnt;
                st.pop();
            }
            if (saved[i][j] > max_num) {
                max_num = saved[i][j];
                room_num = map[i][j];
            } else if (saved[i][j] == max_num && map[i][j] < room_num) {
                room_num = map[i][j];
            }
        }
    }
}

void init() {
    room_num = 1e6 + 1;
    max_num = 0;
    scanf("%d", &n);
    map = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &map[i][j]);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        init();
        bfs();
        printf("#%d %d %d\n", test_case, room_num, max_num);
    }
    return 0;
}
