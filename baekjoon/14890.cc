#include <iostream>
#include <vector>

using namespace std;

int n, l, road_num = 0;
vector<vector<int>> map, flip_map;

void check_road(vector<int> &v) {
    vector<bool> check(n);
    int prev = v[0], low_cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (low_cnt) {
            if (prev != v[i])
                return;
            check[i] = true;
            --low_cnt;
            continue;
        }
        switch (prev - v[i]) {
            case 1:
                low_cnt = l - 1;
                check[i] = true;
                prev = v[i];
                break;
            case 0:
                break;
            case -1:
                for (int j = 1; j <= l; ++j) {
                    if (i - j < 0 || v[i - j] != prev || check[i - j])
                        return;
                    check[i - j] = true;
                }
                prev = v[i];
                break;
            default:
                return;
        }
    }
    if (!low_cnt)
        ++road_num;
}

int main() {
    scanf("%d%d", &n, &l);
    map = vector<vector<int>>(n, vector<int>(n));
    flip_map = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &map[i][j]);
            flip_map[j][i] = map[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        check_road(map[i]);
        check_road(flip_map[i]);
    }
    printf("%d", road_num);
    return 0;
}
