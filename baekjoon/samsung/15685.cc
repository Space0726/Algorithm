#include <iostream>
#include <vector>

using namespace std;

struct DragonCurve {
    int x;
    int y;
    int d;
    int g;
    DragonCurve(int a, int b, int c, int d_): x(a), y(b), d(c), g(d_) {}
};

int n;
vector<DragonCurve> dc;
vector<vector<bool>> dc_map;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void set_dragon_curve() {
    int xx, yy, new_dir, size;
    for (int i = 0; i < dc.size(); ++i) {
        dc_map[dc[i].x][dc[i].y] = true;
        xx = dc[i].x + dx[dc[i].d];
        yy = dc[i].y + dy[dc[i].d];
        dc_map[xx][yy] = true;
        vector<int> dir = {dc[i].d};
        size = 1;
        for (int j = 0; j < dc[i].g; ++j) {
            for (int k = size - 1; k >= 0; --k) {
                new_dir = (dir[k] + 1) % 4;
                xx += dx[new_dir];
                yy += dy[new_dir];
                dc_map[xx][yy] = true;
                dir.push_back(new_dir);
                ++size;
            }
        }
    }
}

int calc_answer() {
    int ans = 0, xx, yy;
    int cx[4] = {0, 0, 1, 1};
    int cy[4] = {0, 1, 1, 0};
    bool is_dc;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            is_dc = true;
            for (int k = 0; k < 4; ++k) {
                xx = i + cx[k];
                yy = j + cy[k];
                if (!dc_map[xx][yy]) {
                    is_dc = false;
                    break;
                }
            }
            if (is_dc) ++ans;
        }
    }
    return ans;
}

int main() {
    int a, b, c, d_;
    scanf("%d", &n);
    dc_map = vector<vector<bool>>(101, vector<bool>(101));
    dc = vector<DragonCurve>();
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a, &b, &c, &d_);
        dc.push_back(DragonCurve(b, a, c, d_));
    }
    set_dragon_curve();
    printf("%d\n", calc_answer());
    return 0;
}
