#include <iostream>
#include <vector>

using namespace std;

int n, b, c;
long long ans = 0;

int main() {
    int tmp;
    scanf("%d", &n);
    vector<int> number;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        number.push_back(tmp);
    }
    scanf("%d%d", &b, &c);

    for (int i = 0; i < n; ++i) {
        number[i] -= b;
        ++ans;
        if (number[i] > 0) {
            tmp = number[i] / c;
            ans += tmp;
            if (number[i] % c)
                ++ans;
        }
    }
    printf("%lld", ans);
    return 0;
}
