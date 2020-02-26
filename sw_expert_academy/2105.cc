#include <iostream>

using namespace std;

int n, map[20][20], max_num;
int dx[4] = {0, 1, 2, 1};
int dy[4] = {0, 1, 0, -1};

bool is_wall(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void find_max_num() {
    int ans = -1, cnt, xx, yy;
    bool check[100];
    for (int i = 0; i < n-1; ++i) {
        cnt = 0;
        for (int j = 0; j < max_num - 1; ++j)
            check[j] = false;
        for (int j = 1; j < n-1; ++j) {
            for (int k = 0; k < 4; ++k) {
                xx = i + dx[k];
                yy = j + dy[k];
                if (is_wall(xx, yy) || check[map[xx][yy] - 1])
                    goto next;
                ++cnt;
                check[map[xx][yy] - 1] = true;
            }
            ans = ans < cnt ? cnt : ans;
next:
        }
        if (ans == 2*(n - 1))
            return ans;
    }
    return ans;
}

int main() {
    freopen("input_2105.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        max_num = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                scanf("%d", &map[i][j]);
                max_num = max_num < map[i][j] ? map[i][j] : max_num;
            }
        printf("#%d %d\n", test_case, find_max_num());
    }
    return 0;
}
