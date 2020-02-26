#include <iostream>

using namespace std;

int n, m, arr[8] = {1, 2, 3, 4, 5, 6, 7, 8}, t[8] = {0,};
bool check[8] = {false,};

void perm(int k) {
    if (k == m) {
        for (int i = 0; i < m; ++i)
            printf("%d ", t[i]);
        putchar('\n');
    } else {
        for (int i = 0; i < n; ++i) {
            if (check[i]) continue;
            t[k] = arr[i];
            check[i] = true;
            perm(k + 1);
            check[i] = false;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    perm(0);
    return 0;
}
