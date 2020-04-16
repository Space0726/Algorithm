#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Tree { int r, c, year; };
int N, M, K, A[10][10];
vector<vector<int>> nut;
vector<int> trees[10][10];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void get_money() {
    stack<Tree> dead;
    stack<pair<int, int>> breed;

    while (K--) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                sort(trees[i][j].begin(), trees[i][j].end());

        // Spring
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (trees[i][j].size()) {
                    vector<int> tmp;
                    for (int k = 0; k < trees[i][j].size(); ++k) {
                        if (nut[i][j] < trees[i][j][k]) {
                            dead.push({i, j, trees[i][j][k]});
                        } else {
                            nut[i][j] -= trees[i][j][k]++;
                            if (!(trees[i][j][k] % 5)) breed.push({i, j});
                            tmp.push_back(trees[i][j][k]);
                        }
                    }
                    if (tmp.size() != trees[i][j].size())
                        trees[i][j] = tmp;
                }

        // Summer
        while (!dead.empty()) {
            Tree t = dead.top();
            nut[t.r][t.c] += t.year >> 1;
            dead.pop();
        }

        // Fall
        while (!breed.empty()) {
            int x = breed.top().first, y = breed.top().second;
            for (int i = 0; i < 8; ++i) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx < 0 || xx >= N || yy < 0 || yy >= N) continue;
                trees[xx][yy].push_back(1);
            }
            breed.pop();
        }

        // Winter
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                nut[i][j] += A[i][j];
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    nut = vector<vector<int>>(N, vector<int>(N, 5));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &A[i][j]);
    for (int i = 0; i < M; ++i) {
        int t1, t2, t3;
        scanf("%d%d%d", &t1, &t2, &t3);
        trees[t1-1][t2-1].push_back(t3);
    }
    get_money();
    int ans = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            ans += trees[i][j].size();
    printf("%d", ans);
    return 0;
}
