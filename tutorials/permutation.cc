#include <cstdio>
#include <algorithm>

using namespace std;

int a[3] = { 1, 2, 3 };
int t[2];

void print_arr() {
	for (int a : t)
		printf("%d ", a);
	putchar('\n');
}

// n = 3, r = 2
void perm(int n, int r) {
	if (r == 0)
		print_arr();
	else {
		for (int i = n - 1; i >= 0; i--) {
			swap(a[i], a[n - 1]);
			t[r - 1] = a[n - 1];
			perm(n - 1, r - 1);
			swap(a[i], a[n - 1]);
		}
	}
}

// k = 0
void perm2(int n, int r, int k) {
	if (k == r)
		print_arr();
	else
		for (int i = k; i < n - 1; i++) {
			swap(k, i);
			perm2(n, r, k + 1);
			swap(k, i);
		}
}
// 12, 13, 21, 23, 32, 31

// k = 0
bool visited[3 - 1]; // n - 1, integer 변수 하나로 비트연산하여 대신할 수 있음
void perm3(int n, int r, int k) {
	if (k == r)
		print_arr();
	else
		for (int i = 0; i < n - 1; i++) {
			if (visited[i])
				continue;
			t[k] = a[i];
			visited[i] = true;
			perm3(n, r, k + 1);
			visited[i] = false;
		}
}
// 12, 13, 21, 23, 31, 32

int main() {
    perm(3, 2);
    // perm2(3, 2, 0);
    // perm3(3, 2, 0);
}
