#include <cstdio>

using namespace std;

int main() {
    int n, div_sum;
    scanf("%d", &n);
    int min_div = n;
    for (int x = n-1; x >= n/2; x--) {
        div_sum = x;
        for (int i = 10; i <= x*10; i *= 10)
            div_sum += (x % i)/(i / 10);
        if (div_sum == n)
            min_div = x;
    }

    if (min_div == n)
        printf("0\n");
    else
        printf("%d\n", min_div);
    return 0;
}
