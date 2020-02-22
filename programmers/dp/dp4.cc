#include <iostream>
#include <vector>

using namespace std;
int main() {
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = {{2,2}};
    vector<vector<int>> dp(n, vector<int> (m));

    for (const auto &p: puddles)
        dp[p[1]-1][p[0]-1] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] < 0)
                continue;
            if (i == 0 || j == 0)
                dp[i][j] = 1;
            else if (dp[i-1][j] < 0 && dp[i][j-1] < 0)
                dp[i][j] = -1;
            else {
                if (dp[i-1][j] < 0)
                    dp[i][j] = dp[i][j-1];
                else if (dp[i][j-1] < 0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    for (const auto &i: dp) {
        for (const auto &j: i)
            cout << j << " ";
        cout << endl;
    }

    cout << dp[n-1][m-1] % 1000000007<< endl;

    return 0;
}
