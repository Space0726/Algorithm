#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, min_num = 1e9 + 1, max_num = -1e9 - 1;
int *a, *op;

int operate() {
    int result = a[0], x, y;

    for (int i = 0; i < n-1; i++) {
        x = result;
        y = a[i+1];
        switch (op[i]) {
        case 0:
            result = x + y;
            break;
        case 1:
            result = x - y;
            break;
        case 2:
            result = x * y;
            break;
        case 3:
            result = x / y;
            break;
        }
    }

    return result;
}

void perm(int n) {
    if (n == 0) {
        int result = operate();
        if (max_num < result)
            max_num = result;
        if (min_num > result)
            min_num = result;
    } else {
        for (int i = n - 1; i >= 0; i--) {
            swap(op[i], op[n - 1]);
            perm(n - 1);
            swap(op[i], op[n - 1]);
        }
    }
}

int main() {
    freopen("input_14888.txt", "r", stdin);
    int i, j, tmp, cnt = 0;
    scanf("%d", &n);
    a = (int*) malloc(sizeof(int) * n);
    op = (int*) malloc(sizeof(int) * (n-1));
    for (i = 0; i < n; i++)
        scanf(" %d", a + i);
    for (i = 0; i < 4; i++) {
        scanf(" %d", &tmp);
        for (j = 0; j < tmp; j++)
            op[cnt + j] = i;
        cnt += tmp;
    }

    perm(n-1);
    printf("%d\n%d", max_num, min_num);

    free(a);
    free(op);
    return 0;
}
