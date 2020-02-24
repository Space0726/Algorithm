#include <cstdio>

using namespace std;

int n, arr[20][20], a[10], b[10], a_idx, b_idx, ans;

void comb(int x) {
    if (!ans)
        return;
    if (x == n) {
        int a_sum = 0, b_sum = 0;
        for (int i = 0; i < n / 2 - 1; ++i) {
            for (int j = i + 1; j < n / 2; ++j) {
                a_sum += arr[a[i]][a[j]] + arr[a[j]][a[i]];
                b_sum += arr[b[i]][b[j]] + arr[b[j]][b[i]];
            }
        }
        a_sum -= b_sum;
        if (a_sum < 0)
            a_sum *= -1;
        ans = ans < a_sum ? ans : a_sum;
        return;
    }
    if (a_idx < n / 2) {
        a[a_idx++] = x;
        comb(x + 1);
        --a_idx;
    }
    if (b_idx < n / 2) {
        b[b_idx++] = x;
        comb(x + 1);
        --b_idx;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d", &n);
        ans = 1e31;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &arr[i][j]);
        comb(0);
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
