#include <iostream>
#include <vector>

using namespace std;

int n, m, max_sum = 4;
vector<vector<int>> v;

void check_1() {
    int sum, x, y, xx, yy;
    int dx[2][4] = { {0, 1, 2, 3}, {0, 0, 0, 0} };
    int dy[2][4] = { {0, 0, 0, 0}, {0, 1, 2, 3} };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            x = i, y = j;
            for (int a = 0; a < 2; ++a) {
                sum = 0;
                for (int b = 0; b < 4; ++b) {
                    xx = x + dx[a][b]; yy = y + dy[a][b];
                    if (xx >= n || yy >= m)
                        break;
                    sum += v[xx][yy];
                    if (b == 3 && max_sum < sum)
                        max_sum = sum;
                }
            }
        }
    }
}

void check_2() {
    int sum, x, y, xx, yy;
    int dx[4] = { 0, 1, 0, 1 };
    int dy[4] = { 0, 0, 1, 1 };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            x = i, y = j;
            sum = 0;
            for (int b = 0; b < 4; ++b) {
                xx = x + dx[b]; yy = y + dy[b];
                if (xx >= n || yy >= m)
                    break;
                sum += v[xx][yy];
                if (b == 3 && max_sum < sum)
                    max_sum = sum;
            }
        }
    }
}

void check_3() {
    int sum, x, y, xx, yy;
    int dx[8][4] = {
        {0, 1, 2, 2},
        {0, 1, 2, 2},
        {0, 1, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 1, 2},
        {0, 0, 1, 2}
    };
    int dy[8][4] = {
        {0, 0, 0, 1},
        {0, 0, 0, -1},
        {0, 0, -1, -2},
        {0, 0, 1, 2},
        {0, 1, 2, 0},
        {0, 1, 2, 2},
        {0, 1, 1, 1},
        {0, 1, 0, 0}
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            x = i, y = j;
            for (int a = 0; a < 8; ++a) {
                sum = 0;
                for (int b = 0; b < 4; ++b) {
                    xx = x + dx[a][b]; yy = y + dy[a][b];
                    if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                        break;
                    sum += v[xx][yy];
                    if (b == 3 && max_sum < sum)
                        max_sum = sum;
                }
            }
        }
    }
}

void check_4() {
    int sum, x, y, xx, yy;
    int dx[4][4] = { {0, 1, 1, 2}, {0, 1, 1, 2}, {0, 0, 1, 1}, {0, 0, 1, 1} };
    int dy[4][4] = { {0, 0, -1, -1}, {0, 0, 1, 1}, {0, 1, 1, 2}, {0, -1, -1, -2} };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            x = i, y = j;
            for (int a = 0; a < 4; ++a) {
                sum = 0;
                for (int b = 0; b < 4; ++b) {
                    xx = x + dx[a][b]; yy = y + dy[a][b];
                    if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                        break;
                    sum += v[xx][yy];
                    if (b == 3 && max_sum < sum)
                        max_sum = sum;
                }
            }
        }
    }
}

void check_5() {
    int sum, x, y, xx, yy;
    int dx[4][4] = { {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1}, {0, 1, 2, 1} };
    int dy[4][4] = { {0, 1, 2, 1}, {0, 0, 0, 1}, {0, 0, -1, 1}, {0, 0, 0, -1} };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            x = i, y = j;
            for (int a = 0; a < 4; ++a) {
                sum = 0;
                for (int b = 0; b < 4; ++b) {
                    xx = x + dx[a][b]; yy = y + dy[a][b];
                    if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                        break;
                    sum += v[xx][yy];
                    if (b == 3 && max_sum < sum)
                        max_sum = sum;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    v = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &v[i][j]);
    check_1();
    check_2();
    check_3();
    check_4();
    check_5();
    printf("%d\n", max_sum);
    return 0;
}
