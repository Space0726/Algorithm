#include <iostream>
#include <vector>

using namespace std;
int main(void) {
	vector<vector<int>> triangle = {{7}, {3,8}, {8,1,0}, {2,7,4,4}, {4,5,2,6,5}};
	
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j <= i; j++)
			cout << triangle[i][j] << " ";
		cout << endl;
	}
	
	vector<int> path;

	return 0;
}
