#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
vector<int> v;
set<int> s;

void subset(int k, int sum) {
    if (k == n) {
        s.insert(sum);
    } else {
        sum += v[k];
        subset(k + 1, sum);
        sum -= v[k];
        subset(k + 1, sum);
    }
}

int main() {
    freopen("input_3752.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        scanf("%d", &n);
        v = vector<int>(n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &v[i]);
        subset(0, 0);
        printf("#%d %lu\n", test_case, s.size());
    }
    return 0;
}
