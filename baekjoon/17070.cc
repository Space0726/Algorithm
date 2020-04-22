#include <iostream>

using namespace std;

int N, house[16][16], ans;

bool is_wall(int x, int y, int dir) {
    if (dir < 2) return house[x][y];
    return house[x-1][y] || house[x][y-1] || house[x][y];
}

void find(int x, int y, int dir) {
    if (is_wall(x, y, dir)) return;
    if (x == N-1 && y == N-1) { ++ans; return; }
    if (dir == 0 && y != N-1) {
        find(x, y+1, 0);
        if (x != N-1) find(x+1, y+1, 2);
    } else if (dir == 1 && x != N-1) {
        find(x+1, y, 1);
        if (y != N-1) find(x+1, y+1, 2);
    } else if (dir == 2) {
        if (y == N-1) {
            find(x+1, y, 1);
        } else if (x == N-1) {
            find(x, y+1, 0);
        } else {
            find(x+1, y, 1);
            find(x, y+1, 0);
            find(x+1, y+1, 2);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &house[i][j]);
    find(0, 1, 0);
    printf("%d", ans);
    return 0;
}
