#include <iostream>

using namespace std;

int N, inning[50][9], ans = 0, p[9], order[8] = { 0, 1, 2, 4, 5, 6, 7, 8 };

void score() {
    int cnt = 0, cur = 0, result;
    for (int i = 0; i < N; ++i) {
        int out = 0, base[4] = { 0, 0, 0, 0 };
        while (out != 3) {
            result = inning[i][p[cur]];
            if (result) {
                if (result == 4) ++cnt;
                else base[0] = 1;
                for (int j = 3; j >= 0; --j)
                    if (base[j]) {
                        if (j + result > 3) ++cnt;
                        else base[j+result] = base[j];
                        base[j] = 0;
                    }
            } else ++out;
            if (++cur == 9) cur = 0;
        }
    }
    if (ans < cnt) ans = cnt;
}

inline void swap(int a, int b) {
    int t = order[a];
    order[a] = order[b];
    order[b] = t;
}

void perm(int k) {
    if (k == 8) {
        for (int i = 0; i < 8; ++i)
            p[order[i]] = i + 1;
        score();
    } else {
        for (int i = k; i < 8; ++i) {
            swap(k, i);
            perm(k + 1);
            swap(k, i);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 9; ++j)
            scanf("%d", &inning[i][j]);
    perm(0);
    printf("%d", ans);
    return 0;
}
