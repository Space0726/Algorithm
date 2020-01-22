#include <cstdio>

using namespace std;

int main() {
    int n, i, j;
    scanf("%d", &n);
    for (i = n*n - 1; i >= n*n - n; i--) {
        for (j = 0; j < n; j++)
            printf("%c ", (i - n*j)%26 + 'A');
        putchar('\n');
    }

    return 0;
}
