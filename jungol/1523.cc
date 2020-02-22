#include <cstdio>

using namespace std;

int main() {
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    if (n < 1 || n > 100 || m < 1 || m > 3)
        printf("INPUT ERROR!");
    else {
        switch (m) {
        case 1:
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    if (i >= j)
                        putchar('*');
                    else
                        putchar(' ');
                }
                putchar('\n');
            }
            break;
        case 2:
            for (i = 1; i <= n; i++) {
                for (j = n; j > 0; j--) {
                    if (i <= j)
                        putchar('*');
                    else
                        putchar(' ');
                }
                putchar('\n');
            }
            break;
        case 3:
            for (i = 0; i < n; i++) {
                for (j = 0; j < 2*(n-1) + 1; j++) {
                    if (n - 1 - i <= j && n - 1 + i >= j)
                        putchar('*');
                    else
                        putchar(' ');
                }
                putchar('\n');
            }
            break;
        }
    }

    return 0;
}
