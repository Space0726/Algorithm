#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<int> &v) {
    for (const auto &i: v)
        cout << i << " ";
    cout << endl;
}

int main(void) {
	vector<vector<int>> triangle = {{7}, {3,8}, {8,1,0}, {2,7,4,4}, {4,5,2,6,5}};
    int size = triangle.size();
    vector<int> dp(size);
    
    dp[0] = triangle[0][0];
    for (int i = 1; i < size; i++) {
        print_vector(dp);
        for (int j = i; j >= 0; j--) {
            if (i == j)
                dp[j] = dp[j-1] + triangle[i][j];
            else if (j == 0)
                dp[j] += triangle[i][j];
            else {
                if (triangle[i][j] + dp[j] > triangle[i][j] + dp[j-1])
                    dp[j] += triangle[i][j];
                else
                    dp[j] = triangle[i][j] + dp[j-1];
            }
        }
    }

    print_vector(dp);
	cout << *max_element(dp.begin(), dp.end()) << endl;
	return 0;
}
