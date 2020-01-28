#include <cstdio>

using namespace std;

int main() {
    int n, i, j;
    scanf("%d", &n);
    if (n < 1 || n  > 100 || !(n&1))
        puts("INPUT ERROR!");
    else {
        for (i = 0; i < n; i++) {
            for (j = (i <= n/2 ? 0 : 2*(i - n/2)); j < i; j++)
                putchar(' ');
            for (j = (i <= n/2 ? 0 : 4*(i - n/2)); j < 2*i+1; j++)
                putchar('*');
            putchar('\n');
        }
    }

    return 0;
}
