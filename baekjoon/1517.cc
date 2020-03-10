#include <iostream>

using namespace std;

int N, cnt, arr[500000], t[500000], t_cnt, a[500000];

inline void swap(int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
    ++t_cnt;
}

void merge_sort(int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    int i = left, j = mid + 1;
    for (int k = left; k <= right; ++k) {
        if (i > mid) t[k] = arr[j++];
        else if (j > right) t[k] = arr[i++];
        else if (arr[i] <= arr[j]) t[k] = arr[i++];
        else t[k] = arr[j++];
    }
    for (i = left; i <= right; ++i)
        arr[i] = t[i];
}

void bubble_sort() {
    for (int i = N - 1; i >= 0; --i)
        for (int j = 0; j < i; ++j)
            if (a[j] > a[j + 1])
                swap(i, j);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
        a[i] = arr[i];
    }
    bubble_sort();
    merge_sort(0, N - 1);
    printf("%d %d\n", t_cnt, cnt);
    return 0;
}
