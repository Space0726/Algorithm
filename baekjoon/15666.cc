#include <iostream>

using namespace std;

int N, M, arr[8], t[8];

void comb(int k, int s) {
    if (k == M) {
        for (int i = 0; i < M; ++i)
            printf("%d ", t[i]);
        putchar('\n');
    } else {
        int before = -1;
        for (int i = s; i < N; ++i) {
            if (before == arr[i]) continue;
            before = arr[i];
            t[k] = arr[i];
            comb(k + 1, i);
        }
    }
}

inline void swap(int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void quick_sort(int left, int right) {
    if (left >= right) return;
    swap(left, (left + right) / 2);
    int i = left, j = right + 1;
    while (i < j) {
        while (arr[left] < arr[--j]);
        while (i < j && arr[left] >= arr[++i]);
        if (i < j) swap(i, j);
    }
    swap(left ,i);
    quick_sort(left, i - 1);
    quick_sort(i + 1, right);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
        scanf("%d", arr + i);
    quick_sort(0, N - 1);
    comb(0, 0);
    return 0;
}
