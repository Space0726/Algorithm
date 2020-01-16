#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int m, n, i, j, a, b;
    int min_rect = 64;
    scanf("%d %d", &m, &n);
    vector<vector<char>> board(m, vector<char>(n));
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf(" %c", &board[i][j]);

    char check[2] = {'W', 'B'};
    bool flag = false;
    int w_cnt, b_cnt;
    for (i = 0; i < m-7; i++)
        for (j = 0; j < n-7; j++) {
            w_cnt = b_cnt = 0;
            for (a = 0; a < 8; a++) {
                for (b = 0; b < 8; b++) {
                    if (board[i+a][j+b] != check[flag])
                        ++w_cnt;
                    else
                        ++b_cnt;
                    flag = !flag;
                }
                flag = !flag;
            }
            if (w_cnt < b_cnt && min_rect > w_cnt)
                min_rect = w_cnt;
            else if (b_cnt <= w_cnt && min_rect > b_cnt)
                min_rect = b_cnt;
        }

    printf("%d\n", min_rect);
    return 0;
}
