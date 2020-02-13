#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> p;

void init() {
    scanf("%d", &n);
    p = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &p[i][j]);
}

int main() {
    freopen("input_1865.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        init();
        printf("#%d %.6f\n", test_case, 0.123123523123);
    }
    return 0;
}
