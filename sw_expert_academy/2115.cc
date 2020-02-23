#include <iostream>

using namespace std;

int n, m, c, honey[10][10];

int calc_max_cost(int x, int y) {

}

int main() {
    freopen("input_2115.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        scanf("%d%d%d", &n, &m, &c);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &honey[i][j]);
    }
    return 0;
}
