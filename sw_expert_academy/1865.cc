#include <iostream>
#include <vector>

using namespace std;

int n;
double max_p;
vector<vector<int>> p;
vector<int> align;
vector<bool> check;

void f(int k, double a) {
    if (a < max_p || a == 0)
        return;
    if (k == n && max_p < a) {
        max_p = a;
    } else {
        for (int i = 1; i <= n; ++i) {
            if (!check[i]) {
                check[i] = true;
                align[k] = i;
                f(k + 1, a/100 * p[k][align[k] - 1]);
                check[i] = false;
            }
        }
    }
}

void init() {
    scanf("%d", &n);
    align = vector<int>(n);
    check = vector<bool>(n + 1);
    max_p = 0;
    p = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &p[i][j]);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        init();
        for (int i = 1; i <= n; ++i) {
            check[i] = true;
            align[0] = i;
            f(1, p[0][i-1]);
            check[i] = false;
        }
        printf("#%d %.6f\n", test_case, max_p);
    }
    return 0;
}
