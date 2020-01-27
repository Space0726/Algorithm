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

int main() {
    int n1, n2, gcd_num;
    scanf("%d %d", &n1, &n2);
    gcd_num = gcd(n1, n2);
    printf("%d\n%d\n", gcd_num, n1*n2/gcd_num);

    return 0;
}
