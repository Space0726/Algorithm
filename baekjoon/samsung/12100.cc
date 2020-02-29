#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0, rotate[5] = {0,};
vector<vector<int>> map;

int slide(vector<vector<int>> &m, int max_num, int dir) {

    return max_num;
}

void perm(vector<vector<int>> &cur_map, int k, int max_num) {
    if (k == 5) return;
    for (int i = 0; i < 4; ++i) {
        rotate[k] = i;
        vector<vector<int>> cp_map = cur_map;
        tmp = slide(cp_map, max_num, rotate[k]);
        perm(cp_map, k + 1, tmp);
    }
}

int main() {
    int tmp;
    scanf("%d", &n);
    map = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &tmp);
            map[i][j] = tmp;
            ans = ans < map[i][j] ? map[i][j] : ans;
        }
    }
    return 0;
}
