#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> money, dp0, dp1;

int dp0_recur(int i) {
    if (dp0[i]) return dp0[i];
    if (i == 0) return 0;
    else if (i == 1) return dp0[1] = money[1];
    return dp0[i] = max(dp0_recur(i-1), dp0_recur(i-2) + money[i]);
}

int dp1_recur(int i) {
    if (dp1[i]) return dp1[i];
    if (i < 3) return dp1[i] = money[0];
    return dp1[i] = max(dp1_recur(i-1), dp1_recur(i-2) + money[i-1]);
}

int main() {
    scanf("%d", &N);
    dp0 = vector<int>(N);
    dp1 = vector<int>(N);
    money = vector<int>(N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &money[i]);
    dp0_recur(N-1);
    dp1_recur(N-1);
    printf("%d", max(dp0[N-1], dp1[N-1]));
    return 0;
}
