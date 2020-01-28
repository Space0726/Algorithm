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
    int gcd_num, lcm_num, i, x, y, t;
    scanf("%d %d", &gcd_num, &lcm_num);
    x = 100000001;
    y = 100000001;
    t = lcm_num;
    for (i = gcd_num; i <= t; i++) {
        t = lcm_num / i * gcd_num;
        if (!(lcm_num%i) && gcd(i, t) == gcd_num) {
            if (x + y > i + t) {
                x = i;
                y = t;
            }
        }
    }
    printf("%d %d", x, y);

    return 0;
}
