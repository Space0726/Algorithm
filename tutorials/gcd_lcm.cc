#include <cstdio>

using namespace std;

// Use Euclidean algorithm
int gcd(int x, int y) {
    int r;
    while (y) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

// Recursive version
int gcd_recur(int x, int y) {
    if (!y)
        return x;
    gcd_recur(y, x % y);
}

// Short version
int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y) {
    if (!x || !y) return 0;
    return x * (y / gcd(x, y));
}

// Extended GCD
pair<int, int> ext_gcd(int x, int y) {
    if (!y) return {1, 0};
    pair<int, int> t = ext_gcd(y, a % y);
    return {t.second, t.first - (a / b) * t.second};
}

int main() {
    int n1, n2, gcd_num;
    scanf("%d %d", &n1, &n2);
    gcd_num = gcd(n1, n2);
    printf("%d\n%d\n", gcd_num, n1*n2/gcd_num);

    return 0;
}
