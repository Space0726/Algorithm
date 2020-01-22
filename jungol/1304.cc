#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n+1; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", i+n*j);
        putchar('\n');
    }

    return 0;
}
