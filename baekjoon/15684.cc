#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
vector<vector<bool>> map;

bool check() {
    for (int i = 0; i <= N; ++i) {
        int cur = i;
        for (int j = 0; j < H; ++j)
            if (map[j][cur]) --cur;
            else if (map[j][cur+1]) ++cur;
        if (cur != i) return false;
    }
    return true;
}

bool combinate(int k, int m) {
    if (k == m) return check();
    for (int j = 1; j <= N; ++j)
        for (int i = 0; i < H; ++i)
            if (!map[i][j-1] && !map[i][j] && !map[i][j+1]) {
                map[i][j] = true;
                if (combinate(k + 1, m)) return true;
                map[i][j] = false;
                while (i < H) {
                    if (map[i][j-1] || map[i][j+1]) break;
                    ++i;
                }
            }
    return false;
}

int set_m() {
    for (int i = 0; i <= 3; ++i) {
        if (i + M > (N-1) * H) return -1;
        if (combinate(0, i)) return i;
    }
    return -1;
}

int main() {
    scanf("%d%d%d", &N, &M, &H);
    map = vector<vector<bool>>(H, vector<bool>(N+2));
    int t1, t2;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &t1, &t2);
        map[t1-1][t2] = true;
    }
    printf("%d", set_m());
    return 0;
}
