#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

set<string> s;
vector<vector<char>> board;
char tmp[7];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int k) {
    if (k == 7) {
        string t;
        for (int i = 0; i < 7; ++i)
            t += tmp[i];
        s.insert(t);
    } else {
        tmp[k] = board[x][y];
        for (int i = 0; i < 4; ++i) {
            if (x + dx[i] < 0 || x + dx[i] >= 4 || y + dy[i] < 0 || y + dy[i] >= 4)
                continue;
            dfs(x + dx[i], y + dy[i], k + 1);
        }
    }
}

int main() {
    int T;
    scanf("%d ", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        board = vector<vector<char>>(4, vector<char>(4));
        s = set<string>();
        for (int i = 0; i < 4; ++i)
            scanf(" %c %c %c %c", &board[i][0], &board[i][1], &board[i][2], &board[i][3]);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                dfs(i, j, 0);
        printf("#%d %lu\n", test_case, s.size());
    }
    return 0;
}
