#include <iostream>

using namespace std;

int x1, y1, x2, y2;

inline int abs(int a) {
    return a < 0 ? -a : a;
}

inline void swap() {
    int t = x2;
    x2 = y2;
    y2 = t;
}

int find_min() {
    int ret = 2 * x2;
    if (x2 == y2) return ret;
    ret += (y2 - x2) / 2 * 4;
    if ((y2 - x2) & 1) ++ret;
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x2 = abs(x2 - x1);
        y2 = abs(y2 - y1);
        if (x2 > y2) swap();
        x1 = y1 = 0;
        printf("#%d %d\n", test_case, find_min());
    }
    return 0;
}
