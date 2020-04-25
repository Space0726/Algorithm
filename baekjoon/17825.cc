#include <cstdio>

using namespace std;
int moves[10], max_sum = 0;
int t[10];
int score[33] = {
    0, 2, 4, 6, 8,
    10, 12, 14, 16, 18,
    20, 22, 24, 26, 28,
    30, 32, 34, 36, 38,
    13, 16, 19, 22, 24,
    28, 27, 26, 25, 30,
    35, 40, 0
};

int move_board(int cur, int num) {
    if (cur >= 32)
        return cur;
    int ret = cur;
    for (int i = 0; i < num; ++i) {
        if (i == 0) {
            switch (ret) {
            case 5:
                ret = 20;
                break;
            case 10:
                ret = 23;
                break;
            case 15:
                ret = 25;
                break;
            case 19:
                ret = 31;
                break;
            case 22: case 24:
                ret = 28;
                break;
            default:
                ++ret;
                break;
            }
        }
        else {
            switch (ret) {
            case 19:
                ret = 31;
                break;
            case 22: case 24:
                ret = 28;
                break;
            default:
                ++ret;
                break;
            }
        }
        if (ret >= 32)
            break;
    }
    return ret;
}

void f(int k) {
    if (k == 10) {
        int sum = 0, tmp;
        int loc[4] = { 0, };
        for (int i = 0; i < 10; ++i) {
            if (loc[t[i] - 1] >= 32)
                return;
            tmp = move_board(loc[t[i] - 1] , moves[i]);
            if (tmp >= 32) {
                loc[t[i] - 1] = tmp;
                continue;
            }
            for (int j = 0; j < 4; ++j)
                if (j != t[i] - 1 && tmp == loc[j])
                    return;
            loc[t[i] - 1] = tmp;
            sum += score[loc[t[i] - 1]];
        }
        if (max_sum < sum)
            max_sum = sum;
        return;
    }
    if (!t[k]) {
        t[k] = 1;
        f(k + 1);
        t[k] = 0;
    }
    if (!t[k]) {
        t[k] = 2;
        f(k + 1);
        t[k] = 0;
    }
    if (!t[k]) {
        t[k] = 3;
        f(k + 1);
        t[k] = 0;
    }
    if (!t[k]) {
        t[k] = 4;
        f(k + 1);
        t[k] = 0;
    }
}

int main() {
    for (int i = 0; i < 10; ++i)
        scanf("%d", moves + i);
    f(0);
    printf("%d\n", max_sum);
    return 0;
}
