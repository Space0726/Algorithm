#include <iostream>

using namespace std;

int N, w[12][12], coord[12][2], dp[12][1 << 10];

inline int abs(int a) { return a < 0 ? -a : a; }

inline int distance(int sx, int sy, int ex, int ey) {
    return abs(sx - ex) + abs(sy - ey);
}

int travel(int node, int visited) {
    if (visited == ((1 << N) - 1)) return w[node][N+1];
    if (dp[node][visited]) return dp[node][visited];
    int ret = 2e9;
    for (int i = 1; i <= N; ++i) {
        if (visited & (1 << (i - 1))) continue;
        int t = w[node][i] + travel(i, visited | (1 << (i - 1)));
        if (t < ret) ret = t;
    }
    return dp[node][visited] = ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d", &N);
        scanf("%d%d%d%d", &coord[0][0], &coord[0][1], &coord[N+1][0], &coord[N+1][1]);
        for (int i = 1; i <= N; ++i)
            scanf("%d%d", &coord[i][0], &coord[i][1]);
        for (int i = 0; i <= N; ++i)
            for (int j = i + 1; j <= N + 1; ++j)
                w[i][j] = w[j][i] = distance(coord[i][0], coord[i][1], coord[j][0], coord[j][1]);
        for (int i = 0; i < N + 2; ++i)
            for (int j = 0; j < 1 << N; ++j)
                dp[i][j] = 0;
        printf("#%d %d\n", test_case, travel(0, 0));
    }
    return 0;
}
