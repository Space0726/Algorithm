#include <iostream>

using namespace std;

struct Player {
    int origin = 0;
    int num = 0;
};

int N, best[500000];
Player arr[500000], t[500000];

void merging(int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    merging(left, mid);
    merging(mid + 1, right);
    int i = left, j = mid + 1;
    for (int k = left; k <= right; ++k) {
        if (i > mid) {
            best[arr[j].origin] += mid + 1 - i;
            t[k] = arr[j++];
        } else if (j > right) {
            t[k] = arr[i++];
        } else if (arr[i].num <= arr[j].num) {
            t[k] = arr[i++];
        } else {
            best[arr[j].origin] += mid + 1 - i;
            t[k] = arr[j++];
        }
    }
    for (i = left; i <= right; ++i)
        arr[i] = t[i];
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        arr[i].origin = i;
        scanf("%d", &arr[i].num);
    }
    merging(0, N - 1);
    for (int i = 0; i < N; ++i)
        printf("%d\n", best[i] + 1);
    return 0;
}
