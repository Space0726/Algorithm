#include <iostream>
#include <cstring>

using namespace std;

int n, m, c, honey[10][10], max_costs[10][10];

int pow(int n) { return n*n; }

void subset(int r, int c_, int k, int amount, int sum) {
    if (k == m) {
        if (max_costs[r][c_] < sum)
            max_costs[r][c_] = sum;
    } else {
        if (amount + honey[r][c_ + k] <= c)
            subset(r, c_, k + 1, amount + honey[r][c_ + k], sum + pow(honey[r][c_ + k]));
        if (amount <= c)
            subset(r, c_, k + 1, amount, sum);
    }
}

int calc_max_cost() {
    int max_sum = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n - m + 1; ++j)
            for (int a = i; a < n; ++a)
                for (int b = 0; b < n - m + 1; ++b) {
                    if (a == i && b <= j + m)
                        continue;
                    if (max_costs[i][j] == -1)
                        subset(i, j, 0, 0, 0);
                    if (max_costs[a][b] == -1)
                        subset(a, b, 0, 0, 0);
                    if (max_sum < max_costs[a][b] + max_costs[i][j])
                        max_sum = max_costs[a][b] + max_costs[i][j];
                }
    return max_sum;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        scanf("%d%d%d", &n, &m, &c);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &honey[i][j]);
        memset(max_costs, -1, sizeof(max_costs));
        printf("#%d %d\n", test_case, calc_max_cost());
    }
    return 0;
}
