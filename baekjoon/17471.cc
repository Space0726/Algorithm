#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n, min_diff;
vector<vector<int>> v;
vector<int> population;
vector<bool> area_a, area_b;

void subset(int k) {
    if (k == n) {
        return;
    }
    if (!area_a[k]) {
        area_a[k] = true;
        subset(k + 1);
        area_a[k] = false;
    }
    if (!area_b[k]) {
        area_b[k] = true;
        subset(k + 1);
        area_b[k] = false;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    for (int t = 0; t < 1; ++t) {
        scanf("%d", &n);
        int tmp;
        v = vector<vector<int>>(n, vector<int>(1));
        area_a = vector<bool>(n);
        area_b = vector<bool>(n);
        population = vector<int>(n);
        min_diff = 100;
        for (int i = 0; i < n; ++i)
            scanf("%d", &population[i]);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i][0]);
            for (int j = 0; j < v[i][0]; ++j) {
                scanf("%d", &tmp);
                v[i].push_back(tmp - 1);
            }
        }
        subset(0);
        min_diff = min_diff == 100 ? -1 : min_diff;
        printf("%d\n", min_diff);
    }
    return 0;
}
