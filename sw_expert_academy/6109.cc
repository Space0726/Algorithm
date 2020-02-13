#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, d;
vector<vector<int>> v;

void move() {
    int x, y;
    vector<vector<bool>> added(n, vector<bool>(n));
    switch (d) {
    case 0:
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                x = i; y = j;
                while (--x >= 0) {
                    if (v[x][y]) {
                        if (added[x][y] || v[x][y] != v[x+1][y])
                            break;
                        v[x][y] *= 2;
                        v[x+1][y] = 0;
                        added[x][y] = true;
                        break;
                    } else {
                        swap(v[x][y], v[x+1][y]);
                    }
                }
            }
        }
        break;
    case 1:
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                x = i; y = j;
                while (++x < n) {
                    if (v[x][y]) {
                        if (added[x][y] || v[x][y] != v[x-1][y])
                            break;
                        v[x][y] *= 2;
                        v[x-1][y] = 0;
                        added[x][y] = true;
                        break;
                    } else {
                        swap(v[x][y], v[x-1][y]);
                    }
                }
            }
        }
        break;
    case 2:
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                x = j; y = i;
                while (++y < n) {
                    if (v[x][y]) {
                        if (added[x][y] || v[x][y] != v[x][y-1])
                            break;
                        v[x][y] *= 2;
                        v[x][y-1] = 0;
                        added[x][y] = true;
                        break;
                    } else {
                        swap(v[x][y], v[x][y-1]);
                    }
                }
            }
        }
        break;
    case 3:
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                x = j; y = i;
                while (--y >= 0) {
                    if (v[x][y]) {
                        if (added[x][y] || v[x][y] != v[x][y+1])
                            break;
                        v[x][y] *= 2;
                        v[x][y+1] = 0;
                        added[x][y] = true;
                        break;
                    } else {
                        swap(v[x][y], v[x][y+1]);
                    }
                }
            }
        }
        break;
    }
}

void print_board() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", v[i][j]);
        putchar('\n');
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        string str;
        cin >> n >> str;
        if (str == "up")
            d = 0;
        else if (str == "down")
            d = 1;
        else if (str == "right")
            d = 2;
        else if (str == "left")
            d = 3;
        v = vector<vector<int>>(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &v[i][j]);
        move();
        printf("#%d\n", test_case);
        print_board();
    }

    return 0;
}
