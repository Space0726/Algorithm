#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

void print_arr(int *t, int r) {
	for (int i = 0; i < r; ++i)
		printf("%d ", *(t + i));
	putchar('\n');
}

void perm(int *a, int *t, int n, int r, int t_num) {
	if (r == 0) {
        print_arr(t, t_num);
    } else {
		for (int i = n - 1; i >= 0; i--) {
			swap(a[i], a[n - 1]);
			t[r - 1] = a[n - 1];
			perm(a, t, n - 1, r - 1, t_num);
			swap(a[i], a[n - 1]);
		}
	}
}

void perm2(int *a, int *t, int n, int r, int k, int t_num) {
	if (k == r) {
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        putchar('\n');
		print_arr(t, t_num);
    } else {
		for (int i = k; i < n; i++) {
			swap(t[k], a[i]);
			perm2(a, t, n, r, k + 1, t_num);
			swap(t[k], a[i]);
		}
    }
}

void perm3(bool *visited, int *a, int *t, int n, int r, int k, int t_num) {
	if (k == r)
		print_arr(t, t_num);
	else
		for (int i = 0; i < n; i++) {
			if (visited[i])
				continue;
			t[k] = a[i];
			visited[i] = true;
			perm3(visited, a, t, n, r, k + 1, t_num);
			visited[i] = false;
		}
}

void perm_trigger(int n, int r, int type) {
    int *a = (int*) malloc(sizeof(int)*n);
    int *t = (int*) malloc(sizeof(int)*r);
    bool *visited = (bool*) calloc(n, sizeof(bool));
    for (int i = 1; i <= n; ++i)
        a[i-1] = i;
    for (int i = 0; i < r; ++i)
        t[i] = 0;
    switch (type) {
    case 1:
        perm(a, t, n, r, r);
        break;
    case 2:
        perm2(a, t, n, r, 0, r);
        break;
    case 3:
        perm3(visited, a, t, n, r, 0, r);
        break;
    }
    free(a);
    free(t);
    free(visited);
}

int main() {
    perm_trigger(5, 3, 3);
    return 0;
}
