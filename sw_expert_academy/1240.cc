#include <iostream>
#include <vector>

using namespace std;

struct Trie {
    int num;
    int next[2];
}

int n, m, start;
vector<vector<char>> v;
Trie root[];

int is_valid(char *str) {

}

void init() {
    scanf("%d %d", &n, &m);
    v = vector<vector<char>>(n, vector<char>(m));
    start = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %c", &v[i][j]);
            if (v[i][j] != '0' && !start)
                start = i;
        }
    }
}

int main() {
    freopen("input_1240.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        init();
    }
    return 0;
}
