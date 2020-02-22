#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, s, c, i;
    scanf("%d %d %d", &m, &s, &c);
    if (m >= c) {
        printf("%d", c);
        return 0;
    }
    int ans = m;
    vector<int> v(c);
    vector<pair<int, int>> v_diff(c-1);
    for (i = 0; i < c; i++)
        scanf(" %d", &v[i]);
    sort(v.begin(), v.end());
    for (i = 0; i < c-1; i++)
        v_diff[i] = make_pair(i, v[i+1]-v[i]);
    sort(v_diff.begin(), v_diff.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });
    vector<bool> check(c-1, true);
    for (i = 0; i < m-1; i++)
        check[v_diff[i].first] = false;

    for (i = 0; i < c-1; i++)
        if (check[v_diff[i].first])
            ans += v_diff[i].second;
    printf("%d", ans);
    
    return 0;
}
