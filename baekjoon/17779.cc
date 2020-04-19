#include <iostream>

using namespace std;

int N, A[20][20], maps[20][20], ans = 2e9;

void update_ans() {
    int pops[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            pops[maps[i][j]] += A[i][j];
    int min_ = pops[0], max_ = pops[0];
    for (int i = 1; i < 5; ++i) {
        if (min_ > pops[i]) min_ = pops[i];
        if (max_ < pops[i]) max_ = pops[i];
    }
    if (ans > max_ - min_) ans = max_ - min_;
}

void make_maps(int x, int y, int d1, int d2) {
    for (int i = 0; i < x + d1; ++i)
        for (int j = 0; j <= y; ++j)
            maps[i][j] = 0;
    for (int i = 0; i <= x + d2; ++i)
        for (int j = y + 1; j < N; ++j)
            maps[i][j] = 1;
    for (int i = x + d1; i < N; ++i)
        for (int j = 0; j < y + d2 - d1; ++j)
            maps[i][j] = 2;
    for (int i = x + d2 + 1; i < N; ++i)
        for (int j = y + d2 - d1; j < N; ++j)
            maps[i][j] = 3;
    for (int i = 0; i <= 2*d1; ++i)
        for (int j = 0; j <= d2 - (i & 1); ++j)
            maps[x + (i+1)/2 + j][y - i/2 + j] = 4;
    update_ans();
}

void brute_force(int x, int y) {
    for (int d1 = 1; d1 <= y; ++d1)
        for (int d2 = 1; d2 <= N - y; ++d2) {
            if (x + d1 + d2 >= N) continue;
            make_maps(x, y, d1, d2);
        }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &A[i][j]);
    for (int i = 0; i < N-2; ++i)
        for (int j = 1; j < N-1; ++j)
            brute_force(i, j);
    printf("%d", ans);
    return 0;
}
