#include <cstdio>

using namespace std;

int main() {
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    switch (m) {
        case 1:
            for (i = 1; i < n+1; i++) {
                for (j = 0; j < n; j++)
                    printf("%d ", i);
                putchar('\n');
            }
            break;
        case 2:
            for (i = 1; i < n+1; i++) {
                if (i&1)
                    for (j = 1; j < n+1; j++)
                        printf("%d ", j);
                else
                    for (j = n; j > 0; j--)
                        printf("%d ", j);
                putchar('\n');
            }
            break;
        case 3:
            for (i = 1; i < n+1; i++) {
                for (j = 1; j < n+1; j++)
                    printf("%d ", i*j);
                putchar('\n');
            }
            break;
    }

    return 0;
}
