#include <cstdio>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int r_, c_, m, ans = 0;

struct Shark {
    int r;
    int c;
    int s;
    int d;
    int z;
    bool is_dead;
    void move() {
        for (int i = 0; i < s; ++i) {
            this->r += dx[this->d];
            this->c += dy[this->d];
            if (this->d < 2) {
                if (this->r < 0) {
                    this->r = 1;
                    this->d = 1;
                } else if (this->r >= r_) {
                    this->r -= 2;
                    this->d = 0;
                }
            } else {
                if (this->c < 0) {
                    this->c = 1;
                    this->d = 2;
                } else if (this->c >= c_) {
                    this->c -= 2;
                    this->d = 3;
                }
            }
        }
    }
};

vector<Shark> sharks;

int main() {
    int nearest, nearest_idx;
    scanf("%d %d %d", &r_, &c_, &m);
    vector<vector<int>> visited;
    if (!m) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        Shark tmp;
        scanf("%d %d %d %d %d", &tmp.r, &tmp.c, &tmp.s, &tmp.d, &tmp.z);
        --tmp.r; --tmp.c; --tmp.d;
        tmp.is_dead = false;
        sharks.push_back(tmp);
    }
    for (int i = 0; i < c_; ++i) {
        nearest = r_;
        for (int j = 0; j < m; ++j) {
            if (!sharks[j].is_dead && sharks[j].c == i && nearest > sharks[j].r) {
                nearest_idx = j;
                nearest = sharks[j].r;
            }
        }
        if (nearest != r_) {
            ans += sharks[nearest_idx].z;
            sharks[nearest_idx].is_dead = true;
        }
        visited = vector<vector<int>>(r_, vector<int>(c_));
        for (int j = 0; j < m; ++j) {
            if (!sharks[j].is_dead) {
                sharks[j].move();
                if (visited[sharks[j].r][sharks[j].c]) {
                    if (sharks[j].z > sharks[visited[sharks[j].r][sharks[j].c] - 1].z) {
                        sharks[visited[sharks[j].r][sharks[j].c] - 1].is_dead = true;
                        visited[sharks[j].r][sharks[j].c] = j + 1;
                    } else {
                        sharks[j].is_dead = true;
                    }
                } else {
                    visited[sharks[j].r][sharks[j].c] = j + 1;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
