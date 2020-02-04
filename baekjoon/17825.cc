#include <cstdio>
#include <vector>

using namespace std;

vector<vector<bool>> board;
int score[33] = {
    0, 2, 4, 6, 8,
    10, 12, 14, 16, 18,
    20, 22, 24, 26, 28,
    30, 32, 34, 36, 38,
    13, 16, 19, 22, 24,
    28, 27, 26, 25, 30,
    35, 40, -1
};

void init() {
    int i;
    board = vector<vector<bool>>(33, vector<bool>(33, false));
    for (i = 0; i < 19; i++)
        board[i][i+1] = true;
    board[4][20] = board[9][23] = board[14][25] = true;
    for (i = 20; i < 22; i++)
        board[i][i+1] = true;
    board[23][24] = true;
    for (i = 25; i < 28; i++)
        board[i][i+1] = true;
    board[24][28] = board[22][28] = true;
    for (i = 28; i < 33; i++)
        board[i][i+1] = true;
    board[19][31] = true;
}

int calc_max_score(int num, int step[10]) {
    int max_score = 0;
    return max_score;
}

int main() {
    int num[10], i;
    for (i = 0; i < 10; i++)
        scanf(" %d", num+i);
    init();
    printf("%d\n", calc_max_score());

    return 0;
}
