#include <iostream>

#define INF 1001

using namespace std;

int N, dist[1000][1000], ans;

void floyd() {
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    ans = 2e9;
    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j)
            sum += dist[i][j];
        ans = ans > sum ? sum : ans;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &dist[i][j]);
                if (!dist[i][j] && i != j)
                    dist[i][j] = INF;
            }
        }
        floyd();
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
