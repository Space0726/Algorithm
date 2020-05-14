#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, A, ans, ma[101], mb[101];
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, 1, 0, -1};
struct BC {
    int num, val;
    BC(): num(0), val(0) {}
    BC(int a, int b): num(a), val(b) {}
};
vector<vector<pair<BC, BC>>> map;

void update_map(int x, int y, BC bc) {
    if (!map[x][y].first.val) {
        map[x][y].first = bc;
    } else if (map[x][y].first.val < bc.val) {
        map[x][y].second = map[x][y].first;
        map[x][y].first = bc;
    } else if (!map[x][y].second.val || map[x][y].second.val < bc.val) {
        map[x][y].second = bc;
    }
}

void update(int X, int Y, int C, int P, int n) {
    int x, y, xx, yy, cnt = 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(10, vector<bool>(10));
    q.push({X, Y});
    visited[X][Y] = true;
    update_map(X, Y, {n, P});
    while (!q.empty()) {
        if (++cnt > C) break;
        int size = q.size();
        for (int step = 0; step < size; ++step) {
            x = q.front().first, y = q.front().second; q.pop();
            for (int i = 1; i < 5; ++i) {
                xx = x + dx[i], yy = y + dy[i];
                if (xx == -1 || xx == 10 || yy == -1 || yy == 10 || visited[xx][yy]) continue;
                update_map(xx, yy, {n, P});
                visited[xx][yy] = true;
                q.push({xx, yy});
            }
        }
    }
}

void find_ans() {
    ans = 0;
    pair<int, int> a = {0, 0}, b = {9, 9};
    for (int i = 0; i <= M; ++i) {
        a.first += dx[ma[i]]; a.second += dy[ma[i]];
        b.first += dx[mb[i]]; b.second += dy[mb[i]];
        pair<BC, BC> tmp_a = map[a.first][a.second];
        pair<BC, BC> tmp_b = map[b.first][b.second];
        if (tmp_a.first.val && !tmp_b.first.val) {
            ans += tmp_a.first.val;
        } else if (!tmp_a.first.val && tmp_b.first.val) {
            ans += tmp_b.first.val;
        } else if (tmp_a.first.val && tmp_b.first.val) {
            if (tmp_a.first.num == tmp_b.first.num) {
                if (tmp_a.second.val && tmp_b.second.val) {
                    if (tmp_a.second.val > tmp_b.second.val)
                        ans += tmp_a.second.val + tmp_b.first.val;
                    else
                        ans += tmp_a.first.val + tmp_b.second.val;
                } else if (tmp_a.second.val && !tmp_b.second.val) {
                    ans += tmp_a.second.val + tmp_b.first.val;
                } else if (!tmp_a.second.val && tmp_b.second.val) {
                    ans += tmp_a.first.val + tmp_b.second.val;
                } else {
                    ans += tmp_a.first.val;
                }
            } else {
                ans += tmp_a.first.val + tmp_b.first.val;
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d%d", &M, &A);
        map = vector<vector<pair<BC, BC>>>(10, vector<pair<BC, BC>>(10));
        for (int i = 0; i < M; ++i)
            scanf("%d", ma + i + 1);
        for (int i = 0; i < M; ++i)
            scanf("%d", mb + i + 1);
        int x, y, c, p, n = 1;
        for (int i = 0; i < A; ++i) {
            scanf("%d%d%d%d", &y, &x, &c, &p);
            update(--x, --y, c, p, n++);
        }
        find_ans();
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
