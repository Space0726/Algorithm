#include <iostream>

using namespace std;

int paper[10][10], ans = 2e9, paper_cnt, paper_num[6] = { 0, 5, 5, 5, 5, 5 };

bool is_match(int x, int y, int size) {
    for (int i = x; i < x + size; ++i)
        for (int j = y; j < y + size; ++j)
            if (!paper[i][j]) return false;
    return true;
}

void fill_check(int x, int y, int size, int val) {
    for (int i = x; i < x + size; ++i)
        for (int j = y; j < y + size; ++j)
            paper[i][j] = val;
}

void find(int x, int y, int sum, int cnt) {
    if (cnt == paper_cnt) {
        if (ans > sum) ans = sum;
        return;
    }
    for (int i = x; i < 10; ++i)
        for (int j = (i == x ? y : 0); j < 10; ++j)
            if (paper[i][j]) {
                for (int k = 5; k > 0; --k) {
                    if (!paper_num[k] || i + k > 10 || j + k > 10) continue;
                    if (sum < ans - 1 && is_match(i, j, k)) {
                        fill_check(i, j, k, 0);
                        --paper_num[k];
                        find(i, j + k, sum + 1, cnt + k*k);
                        fill_check(i, j, k, 1);
                        ++paper_num[k];
                    }
                }
                return;
            }
}

int main() {
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j) {
            scanf("%d", &paper[i][j]);
            if (paper[i][j]) ++paper_cnt;
        }
    find(0, 0, 0, 0);
    printf("%d", ans == 2e9 ? -1 : ans);
    return 0;
}
