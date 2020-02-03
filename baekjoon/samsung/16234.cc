#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, l, r, i, j;
    scanf("%d %d %d", &n, &l, &r);
    vector<vector<int>> v(n, vector<int>(n));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf(" %d", &v[i][j]);
    for (auto a: v) {
        for (auto b: a)
            printf("%d ", b);
        putchar('\n');
    }

    return 0;
}
