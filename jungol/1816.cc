#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("1816_input.txt", "r", stdin);
    int m, s, c, i;
    scanf("%d %d %d", &m, &s, &c);
    vector<int> v(c);
    vector<pair<int, int>> v_diff(c-1);
    scanf(" %d", &v[0]);
    for (i = 1; i < c; i++) {
        scanf(" %d", &v[i]);
        v_diff[i-1] = make_pair(i-1, v[i] - v[i-1]);
    }
    sort(v_diff.begin(), v_diff.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });

    int ans = 0;
    vector<int> stop_idx;
    for (i = 0; i < m-1; i++)
        stop_idx.push_back(v_diff[i].first);
    sort(stop_idx.begin(), stop_idx.end());
    
    for (i = 0; i < m-1; i++)
        if ()
            ans += v_diff[i];

    return 0;
}
