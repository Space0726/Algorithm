#include <iostream>
#include <list>

using namespace std;
int main(void) {
	int n, k, t;
	list<int> l;

	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> t;
		l.push_back(t);
	}

	for(int i: l)
		cout << i << endl;

	l.sort();
	
	for(int i: l)
		cout << i << " ";
	cout << endl;
	return 0;
}
