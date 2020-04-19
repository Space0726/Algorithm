#include <iostream>

using namespace std;

int n = 5, r = 3;
int arr[5] = {1, 2, 3, 4, 5};
int t[3] = {0,};
int visited;

void swap(int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void perm(int k) {
    if (k == r) {
        for (int i = 0; i < r; ++i)
            printf("%d ", arr[i]);
        putchar('\n');
    } else {
        for (int i = k; i < n; ++i) {
            swap(k, i);
            perm(k + 1);
            swap(k, i);
        }
    }
}

void perm_order(int k) {
    if (k == r) {
        for (int i = 0; i < r; ++i)
            printf("%d ", t[i]);
        putchar('\n');
    } else {
        for (int i = 0; i < n; ++i) {
            if (visited & 1 << i) continue;
            t[k] = arr[i];
            visited |= 1 << i;
            perm_order(k + 1);
            visited &= ~(1 << i);
        }
    }
}

void dup_perm(int k) {
    if (k == r) {
        for (int i = 0; i < r; ++i)
            printf("%d ", t[i]);
        putchar('\n');
    } else {
        for (int i = 0; i < n; ++i) {
            t[k] = arr[i];
            dup_perm(k + 1);
        }
    }
}

void comb(int k, int s) {
    if (k == r) {
        for (int i = 0; i < r; ++i)
            printf("%d ", arr[i]);
        putchar('\n');
    } else {
        for (int i = s; i <= n + (k - r); ++i) {
            arr[k] = i;
            comb(k + 1, i + 1);
        }
    }
}

void dup_comb(int k, int s) {
    if (k == r) {
        for (int i = 0; i < r; ++i)
            printf("%d ", t[i]);
        putchar('\n');
    } else {
        for (int i = s; i < n; ++i) {
            t[k] = arr[i];
            dup_comb(k + 1, i);
        }
    }
}

int main() {
    perm_order(0);
    return 0;
}
