#include <iostream>

using namespace std;

int r, c, ans;
char map[20][20];
bool visited[20][20], alpha[26];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int find(int x, int y, int k) {
    ans = ans < k ? k : ans;
    int xx, yy;
    for (int i = 0; i < 4; ++i) {
        xx = x + dx[i];
        yy = y + dy[i];
        if (xx < 0 || xx >= r || yy < 0 || yy >= c || visited[xx][yy] || alpha[map[xx][yy] - 'A'])
            continue;
        visited[xx][yy] = true;
        alpha[map[xx][yy] - 'A'] = true;
        find(xx, yy, k + 1);
        visited[xx][yy] = false;
        alpha[map[xx][yy] - 'A'] = false;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        ans = 0;
        scanf("%d%d", &r, &c);
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                scanf(" %c", &map[i][j]);
        visited[0][0] = true;
        alpha[map[0][0] - 'A'] = true;
        find(0,0, 1);
        visited[0][0] = false;
        alpha[map[0][0] - 'A'] = false;
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
