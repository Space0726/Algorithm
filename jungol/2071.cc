#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    switch (m) {
        case 1: {
            vector<int> v = {1};
            printf("%d\n", v[0]);
            for (i = 1; i < n; i++) {
                v.push_back(1);
                printf("%d ", v[i]);
                for (j = i; j > 1; j--) {
                    v[j] += v[j-1];
                    printf("%d ", v[j]);
                }
                printf("%d\n", v[0]);
            }
            break;
        }
        case 2: {
            vector<vector<int>> v(n, vector<int>(n));
            v[0][0] = 1;
            for (i = 1; i < n; i++) {
                v[i][0] = v[i][i] = 1;
                for (j = 1; j < i; j++)
                    v[i][j] = v[i-1][j-1] + v[i-1][j];
            }
            for (i = n-1; i >= 0; i--) {
                for (j = 1; j < n-i; j++)
                    putchar(' ');
                for (j = 0; j <= i; j++)
                    printf("%d ", v[i][j]);
                putchar('\n');
            }
            break;
        }
        case 3: {
            vector<vector<int>> v(n, vector<int>(n));
            v[n-1][n-1] = 1;
            for (i = n-2; i >= 0; i--) {
                v[n-1][i] = v[i][i] = 1;
                for (j = i; j < n-1; j++)
                    v[j][i] = v[j][i+1] + v[j+1][i+1];
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j <= i; j++)
                    printf("%d ", v[i][j]);
                putchar('\n');
            }
            break;
        }
    }

    return 0;
}
