#include <iostream>
#include <vector>

using namespace std;

int k;
vector<vector<int>> circles, rotate;
vector<int> start;

int calc_start(int s, int offset) {
    int tmp = s + offset;
    if (tmp < 0)
        return tmp + 8;
    return tmp % 8;
}

void rotate_one(int target, int dir) {
    start[target] = calc_start(start[target], -dir);
}

void let_rotate() {
    for (int i = 0; i < k; ++i) {
        vector<vector<int>> cp_circles = circles;
        vector<int> cp_start = start;
        rotate_one(rotate[i][0], rotate[i][1]);
        int prev = rotate[i][1];
        for (int j = rotate[i][0] - 1; j >= 0; --j) {
            if (cp_circles[j][calc_start(cp_start[j], 2)] == cp_circles[j+1][calc_start(cp_start[j+1], 6)])
                break;
            rotate_one(j, -prev);
            prev = -prev;
        }
        prev = rotate[i][1];
        for (int j = rotate[i][0] + 1; j < 4; ++j) {
            if (cp_circles[j][calc_start(cp_start[j], 6)] == cp_circles[j-1][calc_start(cp_start[j-1], 2)])
                break;
            rotate_one(j, -prev);
            prev = -prev;
        }
    }
}

int main() {
    char ch;
    int tmp1, tmp2;
    start = vector<int>(4);
    circles = vector<vector<int>>(4, vector<int>(8));
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 8; ++j) {
            scanf(" %c", &ch);
            circles[i][j] = ch - '0';
        }
    scanf("%d", &k);
    rotate = vector<vector<int>>(k, vector<int>(2));
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &tmp1, &tmp2);
        rotate[i][0] = tmp1 - 1; rotate[i][1] = tmp2;
    }
    let_rotate();
    int ans = 0;
    for (int i = 0; i < 4; ++i)
        ans += circles[i][start[i]] * (1 << i);
    printf("%d\n", ans);
    return 0;
}
