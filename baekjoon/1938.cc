#include <iostream>
#include <queue>

using namespace std;

int N, ans = 2e9, visited[50][50];
char field[50][50];

inline bool is_wall(int x, int y) {
    return x == -1 || x == N || y == -1 || y == N;
}

bool check(int x, int y, int state) {
    if (is_wall(x, y) || field[x][y] == '1' || visited[x][y] & (1 << state)) return false;
    if (state) return !is_wall(x-1, y) && !is_wall(x+1, y) && field[x-1][y] != '1' && field[x+1][y] != '1';
    return !is_wall(x, y-1) && !is_wall(x, y+1) && field[x][y-1] != '1' && field[x][y+1] != '1';
}

bool rot_check(int x, int y, int state) {
    if (visited[x][y] & (1 << !state)) return false;
    for (int i = x-1; i <= x+1; ++i)
        for (int j = y-1; j <= y+1; ++j)
            if (is_wall(i, j) || field[i][j] == '1') return false;
    return true;
}

bool is_ans(int x, int y, int state) {
    if (field[x][y] != 'E') return false;
    if (state) return field[x-1][y] == 'E' && field[x+1][y] == 'E';
    return field[x][y-1] == 'E' && field[x][y+1] == 'E';
}

void bfs(int x, int y, int state) {
    typedef struct _Node {
        int x, y, state;
        _Node() {}
        _Node(int a, int b, int c): x(a), y(b), state(c) {}
    } Node;
    queue<Node> q;
    int cnt = -1, nx, ny, nstate;
    q.push({x, y, state});
    while (!q.empty()) {
        ++cnt;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            nx = q.front().x, ny = q.front().y, nstate = q.front().state; q.pop();
            if (is_ans(nx, ny, nstate)) { ans = cnt; return; }
            if (check(nx+1, ny, nstate)) {
                q.push({nx+1, ny, nstate});
                visited[nx+1][ny] |= (1 << nstate);
            }
            if (check(nx-1, ny, nstate)) {
                q.push({nx-1, ny, nstate});
                visited[nx-1][ny] |= (1 << nstate);
            }
            if (check(nx, ny+1, nstate)) {
                q.push({nx, ny+1, nstate});
                visited[nx][ny+1] |= (1 << nstate);
            }
            if (check(nx, ny-1, nstate)) { 
                q.push({nx, ny-1, nstate});
                visited[nx][ny-1] |= (1 << nstate);
            }
            if (rot_check(nx, ny, nstate)) {
                q.push({nx, ny, !nstate});
                visited[nx][ny] |= (1 << !nstate);
            }
        }
    }
}

int main() {
    int s_x = -1, s_y = -1, state = -1;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            scanf(" %c", &field[i][j]);
            if (field[i][j] == 'B') {
                if (s_x == -1) { s_x = i, s_y = j; }
                else if (state == -1) { state = (s_y == j), s_x = i, s_y = j; }
                else continue;
            }
        }
    visited[s_x][s_y] |= (1 << state);
    bfs(s_x, s_y, state);
    printf("%d", ans == 2e9 ? 0 : ans);
    return 0;
}
