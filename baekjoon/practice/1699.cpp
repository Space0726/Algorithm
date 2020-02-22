#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> dp(n+1, 0);

	for(int i = 1; i <= n; i++) {
		dp[i] = i;
		for(int j = 0; j*j <= i; j++)
			dp[i] = min(dp[i], dp[i-j*j] + 1);
	}

	cout << dp[n] << endl;
	 
	return 0;
}
