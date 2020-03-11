#include <iostream>

using namespace std;

int N, M, arr[8], t[8], visited;

inline void swap(int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void perm(int k) {
    if (k == M) {
        for (int i = 0; i < M; ++i)
            printf("%d ", t[i]);
        putchar('\n');
    } else {
        // This before makes result unduplicated because arr is sorted.
        // If it's not sorted, bool array required.
        // ex) bool before[10001] = {false,}
        // 10001 is range of input number.
        int before = -1;
        for (int i = 0; i < N; ++i) {
            if (visited & (1 << i) || before == arr[i]) continue;
            before = arr[i];
            visited |= 1 << i;
            t[k] = arr[i];
            perm(k + 1);
            visited &= ~(1 << i);
        }
    }
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
    swap(left, i);
    quick_sort(left, i - 1);
    quick_sort(i + 1, right);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
        scanf("%d", arr + i);
    quick_sort(0, N - 1);
    perm(0);
    return 0;
}
