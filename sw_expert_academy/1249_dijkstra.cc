#include <iostream>

using namespace std;

int N, ans, map[100][100], length[10000], touch[10000];

void dijkstra() {
    for 
}

int main() {
    freopen("input_1249.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &map[i][j]);
                length[i*N + j] = touch[i*N + j] = 0;
            }
        }
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
