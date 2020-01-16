#include <cstdio>

using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if ((a>=b && b>=c) || (c>=b && b>=a))
        printf("%d", b);
    else if ((b>=a && a>=c) || (c>=a && a>=b))
        printf("%d", a);
    else
        printf("%d", c);

    return 0;
}
