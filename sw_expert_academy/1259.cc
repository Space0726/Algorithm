#include <iostream>

using namespace std;

typedef struct {
    int r;
    int c;
} Bolt;

int n;
Bolt bolts[20];

void swap(int a, int b) {
    Bolt t = bolts[a];
    bolts[a] = bolts[b];
    bolts[b] = t;
}

bool dfs(int k) {
    if (k == n)
        return true;
    for (int i = k; i < n; ++i) {
        swap(i, k);
        if (bolts[k - 1].c == bolts[k].r && (dfs(k + 1)))
            return true;
        swap(i, k);
    }
    return false;
}

int init() {
    scanf("%d", &n);
    int candidates[30] = {0,};
    int start[2] = {0,};
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &bolts[i].r, &bolts[i].c);
        ++candidates[bolts[i].r - 1];
        ++candidates[bolts[i].c - 1];
    }
    for (int i = 0; i < 30; ++i) {
        if (candidates[i] & 1) {
            if (start[0]) {
                start[1] = i;
                break;
            } else {
                start[0] = i;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (start[j] == bolts[i].r - 1) {
                start[0] = i;
                goto start;
            }
        }
    }
start:
    return start[0];
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        swap(init(), 0);
        dfs(1);
        printf("#%d ", test_case);
        for (int i = 0; i < n; ++i)
            printf("%d %d ", bolts[i].r, bolts[i].c);
        putchar('\n');
    }
    return 0;
}
