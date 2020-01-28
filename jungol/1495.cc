#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, i, j, cnt, num = 1;
    scanf("%d", &n);
    vector<vector<int>> v(n, vector<int>(n));
    for (cnt = 0; cnt < n; cnt++) {
        if (cnt&1)
            for (i = cnt, j = 0; i >= 0; i--, j++)
                v[i][j] = num++;
        else
            for (i = 0, j = cnt; i <= cnt; i++, j--)
                v[i][j] = num++;
    }
    for (cnt = 1; cnt < n; cnt++) {
        if ((n - cnt)&1)
            for (i = cnt, j = n-1; i < n; i++, j--)
                v[i][j] = num++;
        else
            for (i = n-1, j = cnt; i >= cnt; i--, j++)
                v[i][j] = num++;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", v[i][j]);
        putchar('\n');
    }

    return 0;
}
