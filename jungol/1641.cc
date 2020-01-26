#include <cstdio>

using namespace std;

int main() {
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    if (n > 100 || !(n&1) || m < 1 || m > 3) {
        puts("INPUT ERROR!");
    } else {
        switch (m) {
        case 1:
            for (i = 1; i <= n; i++) {
                if (i&1)
                    for (j = 1 + (i-1)*i/2; j <= i*(i+1)/2; j++)
                        printf("%d ", j);
                else
                    for (j = i*(i+1)/2; j >= 1 + (i-1)*i/2; j--)
                        printf("%d ", j);
                putchar('\n');
            }
            break;
        case 2:
            for (i = 0; i < n; i++) {
                for (j = 0; j < i; j++)
                    printf("  ");
                for (j = 0; j < 2*(n-1-i) + 1; j++)
                    printf("%d ", i);
                putchar('\n');
            }
            break;
        case 3:
            for (i = 0; i < n; i++) {
                for (j = 0; j <= (i <= n/2 ? i : n-1-i); j++)
                    printf("%d ", j+1);
                putchar('\n');
            }
            break;
        }
    }

    return 0;
}
