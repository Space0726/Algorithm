#include <iostream>

using namespace std;

int N, arr[500000], t[500000];
long long cnt = 0;

void merge_sort(int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    int i = left, j = mid + 1;
    for (int k = left; k <= right; ++k) {
        if (i > mid) {
            cnt += (mid + 1 - i);
            t[k] = arr[j++];
        } else if (j > right) {
            t[k] = arr[i++];
        } else if (arr[i] <= arr[j]) {
            t[k] = arr[i++];
        } else {
            cnt += (mid + 1 - i);
            t[k] = arr[j++];
        }
    }
    for (i = left; i <= right; ++i)
        arr[i] = t[i];
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", arr + i);
    merge_sort(0, N - 1);
    printf("%lld\n", cnt);
    return 0;
}
