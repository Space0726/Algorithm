#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, num, j, i = 0;
    scanf("%d", &n);
    vector<vector<int>> v(n, vector<int>(n));
    j = n/2;
    v[i][j] = 1;
    for (num = 2; num <= n*n; num++) {
        if ((num - 1)%n) {
            if (--i < 0)
                i = n - 1;
            if (--j < 0)
                j = n - 1;
        } else
            if (++i == n)
                i = 0;
        v[i][j] = num;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", v[i][j]);
        putchar('\n');
    }

    return 0;
}
