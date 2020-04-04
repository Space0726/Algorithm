#include <iostream>
#include <vector>

using namespace std;

int N, M, K, ans;
vector<int> counter;
vector<vector<int>> map;
vector<vector<vector<int>>> sticker;

vector<vector<int>> rot90(vector<vector<int>> &t) {
    int r = t.size(), c = t[0].size();
    vector<vector<int>> ret = vector<vector<int>>(c, vector<int>(r));
    for (int a = 0; a < r; ++a)
        for (int b = 0; b < c; ++b)
            ret[b][r-a-1] = t[a][b];
    return ret;
}

bool is_matched(vector<vector<int>> &t) {
    int r = t.size(), c = t[0].size();
    for (int i = 0; i + r <= N; ++i) {
        for (int j = 0; j + c <= M; ++j) {
            for (int a = 0; a < r; ++a)
                for (int b = 0; b < c; ++b)
                    if (map[i+a][j+b] && t[a][b])
                        goto next;
            for (int a = 0; a < r; ++a)
                for (int b = 0; b < c; ++b)
                    map[i+a][j+b] = t[a][b];
            return true;
next:;
        }
    }
    return false;
}

int main() {
    int r, c;
    scanf("%d%d%d", &N, &M, &K);
    counter = vector<int>(K);
    map = vector<vector<int>>(N, vector<int>(M));
    sticker = vector<vector<vector<int>>>();
    for (int i = 0; i < K; ++i) {
        scanf("%d%d", &r, &c);
        sticker.push_back(vector<vector<int>>(r, vector<int>(c)));
        for (int a = 0; a < r; ++a)
            for (int b = 0; b < c; ++b) {
                scanf("%d", &sticker[i][a][b]);
                if (sticker[i][a][b])
                    ++counter[i];
            }
    }
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (is_matched(sticker[i])) {
                ans += counter[i];
                break;
            } else {
                if (j == 3) break;
                sticker[i] = rot90(sticker[i]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
