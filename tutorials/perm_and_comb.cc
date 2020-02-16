#include <cstdio>
#include <algorithm>

using namespace std;

int arr[5] = { 1, 2, 3, 4, 5 };
int tmp[3] = { 0, };
int visited = 0;
int visited_arr[5] = { 0, };

void print_tmp() {
	for (int i = 0; i < 3; ++i)
		printf("%d ", tmp[i]);
	putchar('\n');
}

void comb_recur(int n, int r) {
    if (r == 0) {
        for (int i = 0; i < 2; ++i)
            printf("%d ", a[i]);
        putchar('\n');
        return;
    } else if (n == 0) {
        return;
    }
    a[r - 1] = n;
    comb_recur(n - 1, r - 1);
    comb_recur(n - 1, r);
}

// C(n, r) = C(n - 1, r - 1) + C(n - 1, r)
void comb(int n, int r) {
	if (r == 0) print_tmp();
	else if (n < r) return;
	else {
		tmp[r - 1] = arr[n - 1];
		comb(n - 1, r - 1);
		comb(n - 1, r);
	}
}

void comb2(int n, int r, int k, int s) {
	if (k == r) print_tmp();
	else
		for (int i = s; i <= n - r + k; i++) {
			tmp[k] = arr[i];
			comb(k + 1, i + 1);
		}
}

void dup_perm(int n, int r) {
	if (r == 0) print_tmp();
	else
		for (int i = 0; i < n; i++) {

		}
}

void dup_comb(int n, int r) {
	if (r == 0) print_tmp();
	else if (n == 0) return;
	else {
		tmp[r - 1] = arr[n - 1];
		dup_comb(n, r - 1);
		dup_comb(n - 1, r);
	}
}

void dup_comb2(int n, int r, int k, int s) {
	if (r == 0) print_tmp();
	else
		for (int i = s; i <= n; i++) {
			tmp[k] = arr[i];
			dup_comb2(n, r, k + 1, i);
		}
}

int main(int argc, char **argv) {
	dup_comb(5, 3);

	return 0;
}
