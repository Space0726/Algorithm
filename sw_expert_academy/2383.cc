#include <iostream>

using namespace std;

int n, p_n, min_time, map[10][10], people[10][2], stair[2][2], stair_len[2];

void go_down() {

}

void init() {
    scanf("%d", &n);
    p_n = 0;
    min_time = 1e31;
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                people[p_n][0] = i;
                people[p_n++][0] = j;
            }
            else if (map[i][j] > 1) {
                stair_len[tmp] = map[i][j];
                stair[tmp][0] = i;
                stair[tmp++][1] = j;
            }
        }
    }
}

int main() {
    freopen("input_2383.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        init();
        go_down();
        printf("#%d %d\n", test_case, min_time);
    }
    return 0;
}
