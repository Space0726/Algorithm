#include <iostream>

using namespace std;

int N, w[12][12], coord[12][2], dist[10][1 << 10];

inline int abs(int a) { return a < 0 ? -a : a; }

inline int distance(int sx, int sy, int ex, int ey) {
    return abs(sx - ex) + abs(sy - ey);
}

inline int min(int a, int b) { return a < b ? a : b; }

int travel() {
    int i, j, k;
    for (i = 1; i <= N; ++i)
        dist[i][i-1] = w[i][0];
    for (k = 1; k <= N; ++k) {
        subset(k);
        dist[0][] = min();
    }
    return dist[0][];
}

int main() {
    freopen("input_1247.txt", "r", stdin);
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
        printf("#%d %d\n", test_case, travel());
    }
    return 0;
}
