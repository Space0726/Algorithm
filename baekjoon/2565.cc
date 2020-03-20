#include <iostream>

using namespace std;

int N, arr[100][2], dp[100], max_len;

inline void swap(int a, int b) {
    int t1 = arr[a][0], t2 = arr[a][1];
    arr[a][0] = arr[b][0], arr[a][1] = arr[b][1];
    arr[b][0] = t1, arr[b][1] = t2;
}

void quick_sort(int left, int right) {
    if (left >= right) return;
    swap(left, (left + right) / 2);
    int i = left, j = right + 1;
    while (i < j) {
        while (arr[left][0] < arr[--j][0]);
        while (i < j && arr[left][0] >= arr[++i][0]);
        if (i < j) swap(i, j);
    }
    swap(left, i);
    quick_sort(left, i - 1);
    quick_sort(i + 1, right);
}

void lis() {
    dp[0] = 1;
    for (int i = 1; i < N; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (arr[j][1] < arr[i][1] && dp[i] <= dp[j])
                dp[i] = dp[j] + 1;
        max_len = max_len < dp[i] ? dp[i] : max_len;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d%d", &arr[i][0], &arr[i][1]);
    quick_sort(0, N - 1);
    lis();
    printf("%d", N - max_len);
    return 0;
}
