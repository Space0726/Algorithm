#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("1931_input.txt", "r", stdin);
    int n, a, b;
    scanf("%d", &n);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        v[i] = make_pair(a, b);
    }

    struct {
        bool operator()(pair<int, int> a, pair<int, int> b) const {
            if (a.second - a.first == b.second - b.first) {
                if (a.first == b.first)
                    return a.second < b.second;
                return a.first < b.first;
            }
            return (a.second - a.first) < (b.second - b.first);
        }
    } comp;
    sort(v.begin(), v.end(), comp);

    for (const auto& q: v)
        printf("%d %d\n", q.first, q.second);

    return 0;
}
