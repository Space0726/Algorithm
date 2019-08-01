#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(void) {
	int R, C, T;
	int temp;
	
	freopen("17144_input.txt", "r", stdin);

	cin >> R >> C >> T;
	vector<vector<int> > v(R, vector<int>());
	vector<int> up, down;
	bool isDown=false;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> temp;
			if (temp == -1) {
				if (isDown) {
					down.push_back(i);
					down.push_back(j);
				}
				else {
					up.push_back(i);
					up.push_back(j);
					isDown=true;
				}
			}
			v[i].push_back(temp);
		}
	}

	//TODO:

	for (vector<int> t: v) {
		for(int i: t)
			cout << i << '\t';
		cout << endl;
	}

	cout << "Up: ";
	for (int i: up)
		cout << i << '\t';

	cout << endl << "Down: ";
	for (int i: down)
		cout << i << '\t';

	cout << endl;

	return 0;
}
