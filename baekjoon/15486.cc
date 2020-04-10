#include <iostream>

using namespace std;

int N, T[1500000], P[1500000], dp[1500000];

void calc() {
    if (T[N-1] == 1) dp[N-1] = P[N-1];
    for (int i = N-2; i >= 0; --i) {
        int flag = i + T[i];
        if (flag == N)
            dp[i] = max(P[i], dp[i+1]);
        else if (flag > N)
            dp[i] = dp[i+1];
        else
            dp[i] = max(P[i] + dp[flag], dp[i+1]);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d%d", &T[i], &P[i]);
    calc();
    printf("%d", dp[0]);
    return 0;
}
