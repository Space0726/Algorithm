#include <iostream>
#include <vector>

using namespace std;

int N, p[5], max_block;
vector<vector<int>> board;

int find_max_block(vector<vector<int>> &v) {
    int ret = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (ret < v[i][j])
                ret = v[i][j];
    return ret;
}

vector<vector<int>> move_block(vector<vector<int>> v, int r) {
    vector<vector<bool>> visited(N, vector<bool>(N));
    int i, j, k;
    switch (p[r]) {
    // To left
    case 0:
        for (i = 0; i < N; ++i) {
            for (j = 1; j < N; ++j) {
                if (!v[i][j]) continue;
                k = j-1;
                if (v[i][k]) {
                    if (v[i][j] == v[i][k] && !visited[i][k]) {
                        v[i][k] <<= 1;
                        v[i][j] = 0;
                        visited[i][k] = true;
                    }
                    continue;
                }
                while (k >= 0 && !v[i][k]) --k;
                if (k == -1) {
                    v[i][0] = v[i][j];
                    v[i][j] = 0;
                    continue;
                }
                if (v[i][j] == v[i][k] && !visited[i][k]) {
                    v[i][k] <<= 1;
                    v[i][j] = 0;
                    visited[i][k] = true;
                } else {
                    if (k != j-1) {
                        v[i][k+1] = v[i][j];
                        v[i][j] = 0;
                    }
                }
            }
        }
        break;
    // To top
    case 1:
        for (i = 0; i < N; ++i) {
            for (j = 1; j < N; ++j) {
                if (!v[j][i]) continue;
                k = j-1;
                if (v[k][i]) {
                    if (v[j][i] == v[k][i] && !visited[k][i]) {
                        v[k][i] <<= 1;
                        v[j][i] = 0;
                        visited[k][i] = true;
                    }
                    continue;
                }
                while (k >= 0 && !v[k][i]) --k;
                if (k == -1) {
                    v[0][i] = v[j][i];
                    v[j][i] = 0;
                    continue;
                }
                if (v[j][i] == v[k][i] && !visited[k][i]) {
                    v[k][i] <<= 1;
                    v[j][i] = 0;
                    visited[k][i] = true;
                } else {
                    if (k != j-1) {
                        v[k+1][i] = v[j][i];
                        v[j][i] = 0;
                    }
                }
            }
        }
        break;
    // To right
    case 2:
        for (i = 0; i < N; ++i) {
            for (j = N-2; j >= 0; --j) {
                if (!v[i][j]) continue;
                k = j+1;
                if (v[i][k]) {
                    if (v[i][j] == v[i][k] && !visited[i][k]) {
                        v[i][k] <<= 1;
                        v[i][j] = 0;
                        visited[i][k] = true;
                    }
                    continue;
                }
                while (k < N && !v[i][k]) ++k;
                if (k == N) {
                    v[i][N-1] = v[i][j];
                    v[i][j] = 0;
                    continue;
                }
                if (v[i][j] == v[i][k] && !visited[i][k]) {
                    v[i][k] <<= 1;
                    v[i][j] = 0;
                    visited[i][k] = true;
                } else {
                    if (k != j+1) {
                        v[i][k-1] = v[i][j];
                        v[i][j] = 0;
                    }
                }
            }
        }
        break;
    // To bottom
    case 3:
        for (i = 0; i < N; ++i) {
            for (j = N-2; j >= 0; --j) {
                if (!v[j][i]) continue;
                k = j+1;
                if (v[k][i]) {
                    if (v[j][i] == v[k][i] && !visited[k][i]) {
                        v[k][i] <<= 1;
                        v[j][i] = 0;
                        visited[k][i] = true;
                    }
                    continue;
                }
                while (k < N && !v[k][i]) ++k;
                if (k == N) {
                    v[N-1][i] = v[j][i];
                    v[j][i] = 0;
                    continue;
                }
                if (v[j][i] == v[k][i] && !visited[k][i]) {
                    v[k][i] <<= 1;
                    v[j][i] = 0;
                    visited[k][i] = true;
                } else {
                    if (k != j+1) {
                        v[k-1][i] = v[j][i];
                        v[j][i] = 0;
                    }
                }
            }
        }
        break;
    }
    return v;
}

void perm(vector<vector<int>> v, int k) {
    if (k == 5) {
        int max_val = find_max_block(v);
        if (max_block < max_val)
            max_block = max_val;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        p[k] = i;
        perm(move_block(v, k), k+1);
    }
}

int main() {
    scanf("%d", &N);
    board = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &board[i][j]);
    perm(board, 0);
    printf("%d\n", max_block);
    return 0;
}
