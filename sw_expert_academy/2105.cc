#include <iostream>
#include <vector>

using namespace std;

int N, map[20][20], ans;
int dx[4] = {1, -1, 1, -1};
int dy[4] = {1, -1, -1, 1};

inline bool is_wall(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void find_ans() {
    vector<bool> visited(101);
    for (int i = 1; i < N-2; ++i) {
        for (int j = 1; j < N-1; ++j) {

        }
    }
}

int main() {
    freopen("input_2105.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= 1; ++test_case) {
        ans = -1;
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                scanf("%d", &map[i][j]);
        find_ans();
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
