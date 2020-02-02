#include <cstdio>

using namespace std;

int pow(int x, int y) {
    if (y == 1)
        return x;
    return x*pow(x, y-1);
}

int main() {
    for (int T = 0; T < 10; T++) {
        int test_case, i, j, x, y;
        scanf("%d %d %d", &test_case, &x, &y);
        printf("#%d %d\n", test_case, pow(x, y));
    }

    return 0;
}
