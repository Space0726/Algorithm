#include <cstdio>

using namespace std;

int n, arr[20][20], start[10], link[10], start_idx, link_idx, ans = 2e9;

void comb(int x) {
    if (!ans)
        return;
    if (x == n) {
        int start_sum = 0, link_sum = 0;
        for (int i = 0; i < n / 2 - 1; ++i) {
            for (int j = i + 1; j < n / 2; ++j) {
                start_sum += arr[start[i]][start[j]] + arr[start[j]][start[i]];
                link_sum += arr[link[i]][link[j]] + arr[link[j]][link[i]];
            }
        }
        start_sum -= link_sum;
        if (start_sum < 0)
            start_sum *= -1;
        ans = ans < start_sum ? ans : start_sum;
        return;
    }
    if (start_idx < n / 2) {
        start[start_idx++] = x;
        comb(x + 1);
        --start_idx;
    }
    if (link_idx < n / 2) {
        link[link_idx++] = x;
        comb(x + 1);
        --link_idx;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &arr[i][j]);
    comb(0);
    printf("%d\n", ans);
    return 0;
}
