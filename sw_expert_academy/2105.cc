#include <iostream>

using namespace std;

int n, map[20][20], max_num;
int dx[4] = {1, -1, 1, -1};
int dy[4] = {1, -1, -1, 1};

bool is_wall(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void find_max_num() {
    int cnt, rx, ry, lx, ly;
    int check[100], cur = 0;
    for (int i = 0; i < n-2; ++i) {
        for (int j = 1; j < n-1; ++j) {
            for (int a = 1; a <= j; ++a) {
                for (int b = 1; b <= n-1-j; ++b) {
                    cnt = 0;
                    ++cur;
                    rx = i; ry = j; lx = i + 2*a; lx = j;
                    for (int c = 0; c < a; ++c) {
                        rx += dx[0]; ry += dy[0];
                        if (is_wall(rx, ry) || check[map[rx][ry] - 1] == cur)
                            goto next;
                        ++cnt;
                        check[map[rx][ry] - 1] = cur;

                        lx += dx[1]; ly += dy[1];
                        if (is_wall(lx, ly) || check[map[lx][ly] - 1] == cur)
                            goto next;
                        ++cnt;
                        check[map[lx][ly] - 1] = cur;
                    }
                    rx = i + a; ry = j + b; lx = i + a; lx = j - b;
                    for (int c = 0; c < b; ++c) {
                        rx += dx[2]; ry += dy[2];
                        if (is_wall(rx, ry) || check[map[rx][ry] - 1] == cur)
                            goto next;
                        ++cnt;
                        check[map[rx][ry] - 1] = cur;

                        lx += dx[3]; ly += dy[3];
                        if (is_wall(lx, ly) || check[map[lx][ly] - 1] == cur)
                            goto next;
                        ++cnt;
                        check[map[lx][ly] - 1] = cur;
                    }
                    max_num = max_num < cnt ? cnt : max_num;
next:;
                }
            }
        }
        if (max_num == 2*(n - 1))
            return;
    }
}

int main() {
    freopen("input_2105.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        max_num = -1;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &map[i][j]);
        find_max_num();
        printf("#%d %d\n", test_case, max_num);
    }
    return 0;
}
