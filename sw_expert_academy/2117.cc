#include <iostream>
#include <vector>

using namespace std;

int N, M, map[20][20];

inline int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d%d", &N, &M);
        int ans = 0;
        vector<pair<int, int>> houses;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) {
                scanf("%d", &map[i][j]);
                if (map[i][j]) houses.push_back({i, j});
            }
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                for (int k = 1; k <= N+1; ++k) {
                    int cnt = 0;
                    for (pair<int, int>& house: houses)
                        if (dist({i, j}, house) < k) ++cnt;
                    int profit = cnt*M - (k*k + (k-1)*(k-1));
                    if (profit >= 0 && ans < cnt) ans = cnt;
                }
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
