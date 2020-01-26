#include <cstdio>

using namespace std;

int main() {
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    if (n > 100 || !(n&1) || m < 1 || m > 4)
        printf("INPUT ERROR!");
    else {
        switch(m) {
        case 1:
            for (i = 0; i < n; i++) {
                for (j = 0; j <= n/2; j++) {
                    if (j <= (n/2 >= i ? i : n-1-i))
                        putchar('*');
                    else
                        putchar(' ');
                }
                putchar('\n');
            }
            break;
        case 2:
            for (i = 0; i < n; i++) {
                for (j = n/2; j < n; j++) {
                    if (j >= (n/2 >= i ? n-1-i : i))
                        putchar('*');
                    else
                        putchar(' ');
                }
                putchar('\n');
            }
            break;
        case 3:
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (n/2 >= i ? (i <= j && j <= n-1-i) : (n-1-i <= j && j <= i))
                        putchar('*');
                    else
                        putchar(' ');
                }
                putchar('\n');
            }
            break;
        case 4:
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (n/2 >= i ? (i <= j && j <= n/2) : (n/2 <= j && j <= i))
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
