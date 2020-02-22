#include <iostream>
#include <vector>

using namespace std;
int dp(vector<int> *v, int idx) {
	if(v->at(idx-1) != 0 || idx == 1) {
		return v->at(idx-1);
	}
	else {
		int t;
		if(idx % 2)
			t = idx + 1;
		else
			t = idx / 2;
		v->at(idx-1) = dp(v, t) + 1;
		return v->at(idx-1);
	}
}

int main(void) {
	int n1, n2;
	int cnt = 0;
	int answer = 0;

	cin >> n1 >> n2;
	vector<int> v(n2+1, 0);
	for(int t = n1; t <= n2; t++) {
		if(v[t-1] == 0)
			dp(&v, t);
		answer += v[t-1];
	}
	cout << "Answer: " << answer << endl;

	return 0;
}
