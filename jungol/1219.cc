#include <cstdio>
#include <vector>

using namespace std;

void print_board(vector<vector<int>> &v) {
    for (auto &a: v) {
        for (auto &b: a)
            printf("%d ", b);
        putchar('\n');
    }
}

int main() {
    freopen("1219_input.txt", "r", stdin);
    int r, c, n, wrong_n, t1, t2;
    scanf("%d %d", &r, &c);
    scanf(" %d", &n);
    scanf(" %d", &wrong_n);
    vector<vector<int>> board(r, vector<int>(c));
    for (int i = 0; i < wrong_n; i++) {
        scanf(" %d %d", &t1, &t2);
        board[t1][t2] = 1;
    }
    print_board(board);

    return 0;
}
