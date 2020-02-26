#include <iostream>

using namespace std;

int n, m, arr[8] = {1, 2, 3, 4, 5, 6, 7, 8}, t[8] = {0,};

void comb(int k, int s) {
    if (k == m) {
        for (int i = 0; i < m; ++i)
            printf("%d ", t[i]);
        putchar('\n');
    } else {
        for (int i = s; i < n; ++i) {
            t[k] = arr[i];
            comb(k + 1, i);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    comb(0, 0);
    return 0;
}
