#include <iostream>

using namespace std;

int n, min_, synergy[16][16];
bool check[16];

int abs(int a) {
    if (a < 0) return -a;
    return a;
}

void f(int l, int k) {
    if (k == n/2) {
        int a_sum = 0, b_sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (check[i] && check[j])
                    a_sum += synergy[i][j] + synergy[j][i];
                else if (!check[i] && !check[j])
                    b_sum += synergy[i][j] + synergy[j][i];
            }
        }
        if (abs(a_sum - b_sum) < min_)
            min_ = abs(a_sum - b_sum);
    } else {
        for (int i = l; i <= n/2 + k; ++i) {
            check[i] = true;
            f(i + 1, k + 1);
            check[i] = false;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        scanf("%d", &n);
        min_ = 1e31;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &synergy[i][j]);
        f(0, 0);
        printf("#%d %d\n", test_case, min_);
    }
    return 0;
}
