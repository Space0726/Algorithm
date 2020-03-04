#include <iostream>

using namespace std;

int N, X, M, cage_info[10][3], max_, ans[10], cage[10];

bool check() {
    int tmp;
    for (int i = 0; i < M; ++i) {
        tmp = 0;
        for (int j = cage_info[i][0]; j <= cage_info[i][1]; ++j)
            tmp += cage[j];
        if (tmp != cage_info[i][2])
            return false;
    }
    return true;
}

void perm(int idx, int sum) {
    if (idx == N) {
        if (check() && max_ < sum) {
            max_ = sum;
            for (int i = 0; i < N; ++i)
                ans[i] = cage[i];
        }
    } else {
        for (int i = 0; i <= X; ++i) {
            cage[idx] = i;
            perm(idx + 1, sum + i);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        max_ = -1;
        scanf("%d%d%d", &N, &X, &M);
        for (int i = 0; i < M; ++i) {
            scanf("%d%d%d", &cage_info[i][0], &cage_info[i][1], &cage_info[i][2]);
            --cage_info[i][0];
            --cage_info[i][1];
        }
        perm(0, 0);
        printf("#%d ", test_case);
        if (max_ == -1) {
            printf("-1\n");
            continue;
        }
        for (int i = 0; i < N; ++i)
            printf("%d ", ans[i]);
        putchar('\n');
    }
    return 0;
}
