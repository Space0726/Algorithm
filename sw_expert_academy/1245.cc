#include <iostream>

using namespace std;

int n;
double mass[10], x[10];

double binary_search(int idx, double start, double cur, double end) {
    double left = 0, right = 0, a, b;
    for (int i = 0; i < n; ++i) {
        a = cur - x[i];
        b = x[i] - cur;
        if (i <= idx)
            left += mass[i] / a / a;
        else
            right += mass[i] / b / b;
    }
    if (left == right || end - cur <= 1e-12 || cur - start <= 1e-12)
        return cur;
    else if (left > right)
        return binary_search(idx, cur, (cur + end) / 2, end);
    return binary_search(idx, start, (start + cur) / 2, cur);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%lf", x + i);
        for (int i = 0; i < n; ++i)
            scanf("%lf", mass + i);
        printf("#%d", test_case);
        for (int i = 0; i < n - 1; ++i)
            printf(" %.10lf", binary_search(i, x[i], (x[i] + x[i + 1]) / 2, x[i + 1]));
        putchar('\n');
    }
    return 0;
}
