#include <iostream>

#define MAX(X, Y) (X < Y ? Y : X)

using namespace std;

int N, lcs[501][501];
char str1[501], str2[501];

// LCS(x_i, y_i) = +-> 0                                      (if i = 0 or j = 0)
//                 +-> LCS(x_i-1, y_j-1) + 1                  (if x_i == y_j)
//                 +-> Max(LCS(x_i, y_j-1), LCS(x_i-1, y_j))  (if x_i != y_j)
//                     if LCS(Substring), line 12 is not contained.
void find_lcs() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (str1[i-1] == str2[j-1])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            // LCS(Substring) is not contained this line. Instead, longest update contained.
            else
                lcs[i][j] = MAX(lcs[i-1][j], lcs[i][j-1]);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d", &N);
        scanf("%s%s", str1, str2);
        find_lcs();
        printf("#%d %.2f\n", test_case, (float) lcs[N][N] / N * 100);
    }
    return 0;
}
