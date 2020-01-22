#include <cstdio>

using namespace std;

int main() {
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j&1)
                printf("%c ", (i + n*(j+1) - (2*i+1))%26 + 'A');
            else
                printf("%c ", (i + n*j)%26 + 'A');
        }
        putchar('\n');
    }

    return 0;
}
