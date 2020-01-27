#include <cstdio>

using namespace std;

int gcd(int x, int y) {
    int r;
    while (y) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main() {
    int N, x, i, gcd_num, lcm_num;
    scanf("%d %d", &N, &gcd_num);
    lcm_num = gcd_num;
    for (i = 1; i < N; i++) {
        scanf(" %d", &x);
        gcd_num = gcd(gcd_num, x);
        lcm_num = lcm_num * x / gcd(lcm_num, x);
    }
    printf("%d %d", gcd_num, lcm_num);

    return 0;
}
