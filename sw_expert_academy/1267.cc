#include <cstdio>
#include <vector>

using namespace std;

int main() {
    for (int test_case = 1; test_case <= 10; ++test_case) {
        int v, e, x, y;
        scanf("%d %d", &v, &e);
        vector<vector<int>> graph(v, vector<int>(v + 2));
        for (int i = 0; i < e; ++i) {
            scanf("%d %d", &x, &y);
            graph[x - 1][++graph[x - 1][1] + 1] = y;
            ++graph[y - 1][0];
        }

        bool is_end = false;
        printf("#%d ", test_case);
        while (!is_end) {
            is_end = true;
            for (int i = 0; i < v; ++i) {
                if (!graph[i][0]) {
                    is_end = false;
                    graph[i][0] = -1;
                    printf("%d ", i + 1);
                    for (int j = 0; j < graph[i][1]; ++j)
                        --graph[graph[i][2 + j] - 1][0];
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
