#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

bool check[10001];
vector<int> scores;

void init() {
    scores = vector<int>(1, 0);
    memset(check, false, sizeof(check));
    check[0] = true;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        int n, num, size;
        scanf("%d", &n);
        init();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &num);
            size = scores.size();
            if (!check[num]) {
                scores.push_back(num);
                check[num] = true;
            }
            for (int j = 1; j < size; ++j) {
                if (!check[scores[j] + num]) {
                    scores.push_back(scores[j] + num);
                    check[scores[j] + num] = true;
                }
            }
        }
        printf("#%d %lu\n", test_case, scores.size());
    }
    return 0;
}
