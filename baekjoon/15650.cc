#include <iostream>

using namespace std;

int n, m, arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

void swap(int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void comb(int k, int s) {
    if (k == m) {
        for (int i = 0; i < m; ++i)
            printf("%d ", arr[i]);
        putchar('\n');
    } else {
        for (int i = s; i <= n + (k - m); ++i) {
            swap(k, i);
            comb(k + 1, i + 1);
            swap(k, i);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    comb(0, 0);
    return 0;
}
