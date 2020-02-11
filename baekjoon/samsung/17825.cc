#include <cstdio>

using namespace std;
int moves[10], max_sum = 0;
int tk1[10], tk2[10], tk3[10], tk4[10];
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
        int tk1_m = 0, tk2_m = 0, tk3_m = 0, tk4_m = 0;
        for (int i = 0; i < 10; ++i) {
            if (tk1[i] && tk1_m < 32) {
                tmp = move_board(tk1_m, moves[i]);
                if (tmp >= 32) {
                    tk1_m = tmp;
                    continue;
                }
                if (tmp == tk2_m || tmp == tk3_m || tmp == tk4_m)
                    return;
                tk1_m = tmp;
                sum += score[tk1_m];
            }
            else if (tk2[i] && tk2_m < 32) {
                tmp = move_board(tk2_m, moves[i]);
                if (tmp >= 32) {
                    tk2_m = tmp;
                    continue;
                }
                if (tmp == tk1_m || tmp == tk3_m || tmp == tk4_m)
                    return;
                tk2_m = tmp;
                sum += score[tk2_m];
            }
            else if (tk3[i] && tk3_m < 32) {
                tmp = move_board(tk3_m, moves[i]);
                if (tmp >= 32) {
                    tk3_m = tmp;
                    continue;
                }
                if (tmp == tk1_m || tmp == tk2_m || tmp == tk4_m)
                    return;
                tk3_m = tmp;
                sum += score[tk3_m];
            }
            else if (tk4[i] && tk4_m < 32) {
                tmp = move_board(tk4_m, moves[i]);
                if (tmp >= 32) {
                    tk4_m = tmp;
                    continue;
                }
                if (tmp == tk1_m || tmp == tk2_m || tmp == tk3_m)
                    return;
                tk4_m = tmp;
                sum += score[tk4_m];
            }
        }
        if (max_sum < sum)
            max_sum = sum;
        return;
    }
    if (!tk1[k]) {
        tk1[k] = 1;
        f(k + 1);
        tk1[k] = 0;
    }
    if (!tk2[k]) {
        tk2[k] = 1;
        f(k + 1);
        tk2[k] = 0;
    }
    if (!tk3[k]) {
        tk3[k] = 1;
        f(k + 1);
        tk3[k] = 0;
    }
    if (!tk4[k]) {
        tk4[k] = 1;
        f(k + 1);
        tk4[k] = 0;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    for (int i = 0; i < 10; ++i)
        scanf("%d", moves + i);

    f(0);
    printf("%d\n", max_sum);
    return 0;
}
