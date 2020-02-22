#include <iostream>
#include <vector>

using namespace std;

int solution(int N, int number) {
    if (number == N)
        return 1;
    int same_nums[8] = {0,}, tmp;
    same_nums[0] = N;
    vector<vector<int>> dp;
    dp.push_back(vector<int>());
    dp[0].push_back(N);
    for (int i = 1; i <= 7; ++i) {
        same_nums[i] = same_nums[i-1]*10 + N;
        if (same_nums[i] == number)
            return i + 1;
        dp.push_back(vector<int>());
        dp[i].push_back(same_nums[i]);
        for (int j = i - 1; j >= 0; --j) {
            for (int a = 0; a < dp[j].size(); ++a) {
                for (int b = 0; b < dp[i-j-1].size(); ++b) {
                    tmp = dp[i-j-1][b] + dp[j][a];
                    if (tmp == number)
                        return i + 1;
                    dp[i].push_back(tmp);
                    tmp = dp[i-j-1][b] - dp[j][a];
                    if (tmp == number)
                        return i + 1;
                    dp[i].push_back(tmp);
                    tmp = dp[i-j-1][b] * dp[j][a];
                    if (tmp == number)
                        return i + 1;
                    dp[i].push_back(tmp);
                    if (dp[j][a] == 0)
                        continue;
                    tmp = dp[i-j-1][b] / dp[j][a];
                    if (tmp == number)
                        return i + 1;
                    dp[i].push_back(tmp);
                }
            }
        }
    }
    return -1;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", solution(a, b));
    return 0;
}
