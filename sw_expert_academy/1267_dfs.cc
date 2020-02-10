#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int main() {
    freopen("input_1267.txt", "r", stdin);
    for (int test_case = 1; test_case <= 10; ++test_case) {
        int v, e, i, j, x, y;
        scanf("%d %d", &v, &e);
        vector<vector<bool>> arr(v, vector<bool>(v));
        for (i = 0; i < e/2; ++i) {
            scanf("%d %d", &x, &y);
            arr[y][x] = true;
        }

        printf("#%d ", test_case);

        vector<vector<bool>> visited(v, vector<bool>(v));
        for (i = 0; i < v; ++i) {
            for (j = 0; j < v; ++j) {
                if (!visited[i][j]) {
                    stack<pair<int, int>> st;
                    st.push(make_pair(i, j));
                    while (!st.empty()) {
                        x = st.top().first;
                        y = st.top().second;
                        for (int k = 0; k < v; ++k) {
                            if (arr[x][k])
                        }
                    }
                }
            }
        }
    }
    return 0;
}
