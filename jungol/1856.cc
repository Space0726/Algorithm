#include <cstdio>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        if (i&1)
            for (int j = m; j > 0; j--)
                printf("%d ", i*m + j);
        else
            for (int j = 1; j < m+1; j++)
                printf("%d ", i*m + j);
        putchar('\n');
    }

    return 0;
}
