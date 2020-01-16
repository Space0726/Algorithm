#include <cstdio>
#include <vector>

using namespace std;

void fill(vector<vector<int>> &v, int n) {
    int i, num = 1;
    int m = n;
    int x = 0, y = -1;
    while (m > 0) {
        for (i = 0; i < m; i++)
            v[x][++y] = num++;
        m--;
        for (i = 0; i < m; i++)
            v[++x][y] = num++;
        for (i = 0; i < m; i++)
            v[x][--y] = num++;
        m--;
        for (i = 0; i < m; i++)
            v[--x][y] = num++;
    }
}

void fill2(vector<vector<int>> &v, int n) {
    int i, x = 1, y = 0, num = 0;
    for (i = 0; i <= n+1; i++) {
        v[0][i] = v[n+1][i] = 1;
        v[i][0] = v[i][n+1] = 1;
    }
    while (num < n*n) {
        while (v[x][y+1] == 0)
            v[x][++y] = ++num;
        while (v[x+1][y] == 0)
            v[++x][y] = ++num;
        while (v[x][y-1] == 0)
            v[x][--y] = ++num;
        while (v[x-1][y] == 0)
            v[--x][y] = ++num;
    }
}

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    vector<vector<int>> v(n, vector<int>(n));
    fill(v, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", v[i][j]);
        putchar('\n');
    }
    vector<vector<int>> v2(n+2, vector<int>(n+2));
    fill2(v2, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ", v2[i][j]);
        putchar('\n');
    }

    return 0;
}
