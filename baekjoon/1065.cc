#include <cstdio>

using namespace std;

bool is_hansu(int n) {
    int decimal = 100;
    int diff = n%10 - n/10%10;
    int comp;
    while (n >= decimal) {
        comp = n/(decimal/10)%10 - n/decimal%10;
        if (comp != diff)
            return false;
        decimal *= 10;
    }
    return true;
}

int main() {
    int n, ans;
    scanf("%d", &n);
    ans = n;
    if (n > 99) {
        ans = 99;
        for (int i = 100; i <= n; i++)
            if (is_hansu(i))
                ++ans;
    }
    printf("%d", ans);

    return 0;
}
