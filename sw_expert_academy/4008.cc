#include <iostream>

using namespace std;

int n, op[4], numbers[12], min_, max_;

void f(int k, int sum) {
    if (k == n) {
        if (sum < min_) min_ = sum;
        if (sum > max_) max_ = sum;
        return;
    }
    if (op[0]) {
        --op[0];
        f(k + 1, sum + numbers[k]);
        ++op[0];
    }
    if (op[1]) {
        --op[1];
        f(k + 1, sum - numbers[k]);
        ++op[1];
    }
    if (op[2]) {
        --op[2];
        f(k + 1, sum * numbers[k]);
        ++op[2];
    }
    if (op[3]) {
        --op[3];
        f(k + 1, sum / numbers[k]);
        ++op[3];
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        min_ = 1e8; max_ = -1e8;
        scanf("%d%d%d%d%d", &n, op, op + 1, op + 2, op + 3);
        for (int i = 0; i < n; ++i)
            scanf("%d", numbers + i);
        f(1, numbers[0]);
        printf("#%d %d\n", test_case, max_ - min_);
    }
    return 0;
}
