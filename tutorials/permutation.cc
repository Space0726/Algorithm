#include <cstdio>
#include <algorithm>

using namespace std;

int a[5] = { 1, 2, 3, 4, 5 };
int t[3] = {0,};

void print_arr() {
	for (int a : t)
		printf("%d ", a);
	putchar('\n');
}

void comb(int n, int r) {
    if (r == 0) {
        for (int i = 0; i < 3; ++i)
            printf("%d ", t[i]);
        putchar('\n');
    } else if (n < r) {
        return;
    } else {
        t[r - 1] = a[n - 1];
        comb(n - 1, r - 1);
        comb(n - 1, r);
    }
}

void perm(int n, int r) {
    if (r == 0) {
        // 5P3 일 때
        for (int i = 2; i < 5; ++i)
            printf("%d ", a[i]);
        putchar('\n');
    } else {
        for (int i = n - 1; i >= 0; --i) {
            swap(a[i], a[n - 1]);
            perm(n - 1, r - 1);
            swap(a[i], a[n - 1]);
        }
    }
}

void perm2(int n, int r, int k) {
    if (k == r) {
        for (int i = 0; i < r; ++i)
            printf("%d ", a[i]);
        putchar('\n');
    } else {
        for (int i = k; i < n; i++) {
            swap(a[k], a[i]);
            perm2(n, r, k + 1);
            swap(a[k], a[i]);
        }
    }
}


// k = 0
bool visited[3 - 1]; // n - 1, integer 변수 하나로 비트연산하여 대신할 수 있음
void perm3(int n, int r, int k) {
	if (k == r) {
		print_arr();
    }
	else
		for (int i = 0; i < n; i++) {
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
    perm(5, 3);
    // perm2(5, 3, 0);
    // perm3(5, 3, 0);
}
